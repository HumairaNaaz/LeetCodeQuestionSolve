class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxEle= *max_element(begin(nums),end(nums));
        int i=0,j=0,countMax=0;
        long long result=0;

        while(j<n){
            if(nums[j]==maxEle){
                countMax++;
            }
            while(countMax>=k){
                result += n-j;

                if(nums[i]==maxEle){
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return result;
        
    }
};