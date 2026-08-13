class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0,j=0,result=0;
        int winSum=0,cnt_zero=0;

        while(j<n){
            winSum=winSum+nums[j];
            while(i<j && (nums[i]==0 || winSum>goal)){
                if(nums[i]==0){
                    cnt_zero++;
                }
                else {cnt_zero=0;}

                winSum=winSum-nums[i];
                i++;
            }

            if(winSum==goal){
                result = result+1+cnt_zero;
            }
            j++;

        }
        return result;
    }
};