class Solution {
public:
int helper(int i , vector<int>nums , vector<int>&arr){
    if(i>=nums.size()) return 0;
    if(arr[i]!=-1) return arr[i];
    int pick=nums[i]+helper(i+2 , nums ,arr);
    int not_pick=helper(i+1 , nums, arr);
    arr[i]=max(pick , not_pick);
    return arr[i];
}
    int rob(vector<int>& nums) {
        vector<int> arr(nums.size(), -1);
        return helper(0 , nums,arr);
        
    }
};