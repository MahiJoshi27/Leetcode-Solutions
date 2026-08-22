class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int count = 1;
        long long curr = 0;

        for (int x : nums) {
            if (curr + x > maxSum) {
                count++;
                curr = x;
            } else {
                curr += x;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int x : nums)
            high += x;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};