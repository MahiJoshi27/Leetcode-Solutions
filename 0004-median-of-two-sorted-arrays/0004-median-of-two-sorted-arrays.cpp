class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Binary search smaller array par karenge
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            // nums1 ka partition
            int cut1 = (low + high) / 2;

            // nums2 ka partition
            int cut2 = (m + n + 1) / 2 - cut1;

            // Left aur right elements
            int left1, right1, left2, right2;

            // nums1
            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            if (cut1 == m)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            // nums2
            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];

            if (cut2 == n)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];

            // Correct partition mil gaya
            if (left1 <= right2 && left2 <= right1) {

                // Total elements odd
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Total elements even
                return (max(left1, left2) +
                        min(right1, right2)) / 2.0;
            }

            // nums1 ka partition left le jaana hai
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // nums1 ka partition right le jaana hai
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};