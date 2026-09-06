class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int cnt=0;

            for(int j=0;j<n-1;j++){
                  int idx1=(i+j)%n;
                  int idx2=(i+j+1)%n;

                  if(s[idx1]==s[idx2]){
                    cnt++;
                  }
            }
             if(k==cnt){
                 ans++;
            }
        }
        return ans;
    }
};