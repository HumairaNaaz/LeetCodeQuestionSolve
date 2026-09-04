class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(nums.empty()){
            return 0;
        }
        int maxEl=nums[0];

        for(int i=0;i<n;i++){
            maxEl=max(nums[i],maxEl);
            int minEl=*min_element(begin(nums)+i ,end(nums));

            int less=maxEl-minEl;
            if(less<=k){
                return i;
            }
        }
        return -1;

    }
};