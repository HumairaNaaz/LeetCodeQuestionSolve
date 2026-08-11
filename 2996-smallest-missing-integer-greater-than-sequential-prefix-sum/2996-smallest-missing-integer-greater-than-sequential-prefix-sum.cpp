class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();  

        int sum=nums[0];
        //sum of longest seq prefix.
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
            {
                sum=sum+nums[i];
            }
            else{
                break;
            }
        }  
        while(find(nums.begin(),nums.end(),sum)!=nums.end()){
            sum++;
        }
        return sum;

        


        
    }
};