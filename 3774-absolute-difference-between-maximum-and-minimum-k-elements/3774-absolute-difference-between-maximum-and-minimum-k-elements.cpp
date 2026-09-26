class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(begin(nums),end(nums)); //2245
        int first=0;
        int sec=0;
        int n=nums.size();

        for(int i=0;i<k;i++){
            first +=nums[i]; //4
        }
         for(int i=n-k;i<n;i++){
            sec +=nums[i]; //4
        }
      
        return abs(first-sec);
        
    }
};