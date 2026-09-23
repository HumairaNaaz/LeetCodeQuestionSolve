class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
         for(int i=0;i<n;i++){
            sum +=nums[i];
            mp[sum]=i;
         }
         if(sum<x){
            return-1;
         }

         int target=sum-x;
         int longSubarrat=INT_MIN;

         sum=0;
         for(int i=0;i<n;i++){
            sum +=nums[i];
            int findSum=sum-target;

            if(mp.find(findSum)!=mp.end()){
                int idx=mp[findSum];
                longSubarrat=max(longSubarrat,i-idx);
            }
         }
         return longSubarrat==INT_MIN ?-1:(n-longSubarrat);
        
    }
};