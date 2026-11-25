class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int result=INT_MIN;
        int zero=0;
        int ones=0;
        for(int i=0;i<=n-2;i++){
            if(s[i]=='1'){
                ones++;
            }
            else{
                zero++;
            }
            result=max(result,zero-ones);
        }
        if(s[n-1]=='1'){
            ones++;
        }
        return result+ones;
        
    }
};