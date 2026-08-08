class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int result=0;
        int lastZeroIndx=-1;

        while(j<nums.size()){
            if(nums[j]==0){
                i=lastZeroIndx+1;
                lastZeroIndx=j;
            }
            result=max(result,j-i);
            j++;
        }
        return result;
        
    }
};