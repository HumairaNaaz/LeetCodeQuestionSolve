class Solution {
public:
    int M =1e9+7;
    int dp[1001][1001];
    int numberOfSets(int n, int k) {
        //base case
        for(int i=0;i<=n-1;i++){
            dp[0][i]=1;
        }

        for(int K=1;K<=k;K++){
               vector<int> prefixSum(n+1,0);
               for(int x=n-1;x>=0;x--){
                prefixSum[x]=(prefixSum[x+1]+dp[K-1][x])%M;
               }
            for(int i=n-1;i>=0;i--){
                int take=prefixSum[i+1];
                int skip=dp[K][i+1]%M;
                dp[K][i]=(take+skip)%M;
            }
        }
        return dp[k][0];
        
    }
};