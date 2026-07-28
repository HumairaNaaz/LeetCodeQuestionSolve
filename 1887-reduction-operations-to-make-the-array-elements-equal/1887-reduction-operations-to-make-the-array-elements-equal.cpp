class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int step=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]!=nums[i-1]){
                step=step+(n-i);
            }
        }
       return step; 
    }
};