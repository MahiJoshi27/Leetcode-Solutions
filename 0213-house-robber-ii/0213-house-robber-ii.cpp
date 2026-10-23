
class Solution {
public:
    int helper(int i, int n, vector<int>& nums, vector<int>& arr) {
        if(i > n) return 0;
        if(arr[i] != -1) return arr[i];
        int rob = nums[i] + helper(i + 2, n, nums, arr);
        int skip = helper(i + 1, n, nums, arr);
        arr[i] = max(rob, skip);
        return arr[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> arr1(n, -1);
        vector<int> arr2(n, -1);
        return max(
            helper(0, n - 2, nums, arr1),
            helper(1, n - 1, nums, arr2)
        );
    }
};
