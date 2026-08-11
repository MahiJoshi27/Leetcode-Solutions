/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzeroes=0;
        for(int i=0 ;i< nums.size() ;i++){
            if(nums[i] !=0){
                swap(nums[i] , nums[nonzeroes]);
                nonzeroes++;
            }
        }
    }
};*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;

        for (int readIndex = 0; readIndex < nums.size(); readIndex++) {
            if (nums[readIndex] != 0) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }

        while (writeIndex < nums.size()) {
            nums[writeIndex] = 0;
            writeIndex++;
        }
    }
};