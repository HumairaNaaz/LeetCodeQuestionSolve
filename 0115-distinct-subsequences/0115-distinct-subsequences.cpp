class Solution {
public:
    typedef long long ll;
    ll dp[1001][1001];

    ll solve(string& s, string& t, int n,int m){
        if(m==0) return 1;
        if(n==0) return 0;
        

        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(s[n-1]==t[m-1]){
            return dp[n][m]=solve(s,t,n-1,m-1)+solve(s,t,n-1,m);
        }
        else{
            return dp[n][m]=solve(s,t,n-1,m);
        }

    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        memset(dp,-1,sizeof(dp));
        return solve(s,t,n,m);
    }
};