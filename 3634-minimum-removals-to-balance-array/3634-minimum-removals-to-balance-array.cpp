class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();

        int minEle=nums[0];
        int maxEle=nums[0];
         int i=0,j=0;
        int L=1;
        sort(nums.begin(),nums.end());

        while(j<n){
            minEle=nums[i];
            maxEle=nums[j];

            while(i<j && maxEle > 1LL* k * minEle){
                i++;
                minEle=nums[i];
            }
             L= max(L,j-i+1);
             j++;
        }
        
        return n-L;
    }
};