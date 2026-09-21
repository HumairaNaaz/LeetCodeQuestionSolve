class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);

        for(int i=0;i<n;i++){
            vector<long long> next(k,0);
            int rem=nums[i]%k;
            //single element subarray
            next[rem]++;
            
            //prev subarray extend
            for(int j=0;j<k;j++){
                if(dp[j]>0){
                    int newRem=(j*rem)%k;
                    next[newRem] +=dp[j];

                }
            }

            //add curr subarray to ans
            for(int j=0;j<k;j++){
                ans[j] +=next[j];
            }

           dp=next;
        }
        return ans;
        
    }
};