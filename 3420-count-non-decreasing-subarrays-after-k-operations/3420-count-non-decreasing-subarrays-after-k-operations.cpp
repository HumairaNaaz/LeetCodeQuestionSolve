class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
         vector<ll> cumSum(n);
         cumSum[0]=nums[0];
         for(int i=1;i<n;i++){
            cumSum[i]=nums[i]+cumSum[i-1];
         }

         //Range Sum
         auto rangeSum= [&](int i,int j)-> long long{
            if(i>j)
                return 0;
            
            return cumSum[j]-((i>0)? cumSum[i-1]:0);
         };

         //NGR[i]=n
         vector<int> NGR(n,n);
         stack<int> st;
         for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                NGR[st.top()]=i;
                st.pop();
            }
            st.push(i);
         }
        //operation[i]=total opens to make[i....n-1] non dec
        vector<ll> operation(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m=NGR[i];
            ll segmentOpr=(1LL*nums[i]*(m-i))-rangeSum(i,m-1);
            operation[i]=segmentOpr+operation[m];
        } 

        //ready for sliding win
        deque<int> deq;
        ll result=0;
        int i=0;
        int j=0;

        while(j<n){
            while(!deq.empty() && nums[deq.back()]<nums[j]){
                deq.pop_back();
            }
            deq.push_back(j);

            //shrink

            while(i<=j){
                int m=deq.front();
                ll oprnCnt=(operation[i]-operation[m]) +(1LL*nums[m]*(j-m+1))-rangeSum(m,j);

                if(oprnCnt<=k) break;

                i++;
                if(deq.front()<i){
                    deq.pop_front();
                }
            }
            result +=(j-i+1);
            j++;
        }
        return result;
        
    }
};