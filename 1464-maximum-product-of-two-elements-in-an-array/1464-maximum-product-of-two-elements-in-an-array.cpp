class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
         long long ans;
         long long maxi=0;
     for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
             ans=1LL*(nums[i]-1)*(nums[j]-1);
             maxi=max(maxi,ans);
        }

     }
    return (int)maxi;    
        
    }
};