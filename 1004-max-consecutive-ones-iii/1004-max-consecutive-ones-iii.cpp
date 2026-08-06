class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left=0 , right=0 , zeros_cnt=0, max_ones=0;
        while(right<n){
            if(nums[right]==0) zeros_cnt++;
            while(zeros_cnt>k){
                if(nums[left]==0) zeros_cnt--;
                left++;
            }
            int cur_len=right-left+1;
            max_ones=max(max_ones , cur_len);
            right++;
        }
        return max_ones;
        
    }
};