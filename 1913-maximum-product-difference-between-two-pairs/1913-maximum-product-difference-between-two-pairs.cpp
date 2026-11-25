class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            int lar=nums[n-1]*nums[n-2];
            int small=nums[0]*nums[1];
            ans=lar-small;
        }
        return ans;
        
    }
};