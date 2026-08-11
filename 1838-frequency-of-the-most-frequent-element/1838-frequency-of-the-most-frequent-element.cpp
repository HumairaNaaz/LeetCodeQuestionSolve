class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int result=0;
        long long original=0;
        int l=0;

        for(int r=0;r<n;r++){
            long long target=nums[r];
            original=original+nums[r];
            long long windowsize=target*(r-l+1);
            long long diff=windowsize-original;

            while(diff>k){
                original -=nums[l];
                l++;

                windowsize = target * (r - l + 1);
                diff = windowsize - original;
            }
            result=max(result,r-l+1);
        }
        return result;
        
    }
};