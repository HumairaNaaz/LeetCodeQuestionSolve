class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> deq;
        vector<long long> cumalativeSum(n,0);
        int result=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                cumalativeSum[j]=nums[j];
            }
            else{
                cumalativeSum[j]=cumalativeSum[j-1]+nums[j];
            }
            if(cumalativeSum[j]>=k){
                result = min(result,j+1);
            }
            //shrink win or not
            while(!deq.empty() && cumalativeSum[j]-cumalativeSum[deq.front()]>=k){
                result = min(result,j-deq.front());
                 deq.pop_front();
            }
            while(!deq.empty() && cumalativeSum[j]<=cumalativeSum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }

          return result==INT_MAX ? -1:result;
    }
};