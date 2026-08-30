class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minElementidx=min_element(begin(nums),end(nums))-begin(nums);
        int maxElementidx=max_element(begin(nums),end(nums))-begin(nums);

        int left=min(minElementidx,maxElementidx);
        int right=max(minElementidx,maxElementidx);

        return min({left+1+n-right , right+1 , n-left});

    }
};