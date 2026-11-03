class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        int maxi=*max_element(begin(nums),end(nums));

        for(int i=0;i<n;i++){
           ans +=maxi-nums[i];
        }
        return ans;
    }
};