class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int len=1;
        int maxl=1;
        //int pivot=nums[0];

        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])==1){
                //pivot=nums[i];
                len++;
            }else if(nums[i]==nums[i-1]){
                continue;
            }else{
                len=1;
            }


            maxl=max(len, maxl);

        }

        return maxl;
        
    }
};