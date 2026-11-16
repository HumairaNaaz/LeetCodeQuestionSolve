class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();//col
        int ans=0;
        vector<int> rowcnt(m,0);
        vector<int> colcnt(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    rowcnt[i]++;
                    colcnt[j]++;  
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) continue;
                if(rowcnt[i]==1 && colcnt[j]==1){  
                   ans++;
                }
            }
        }
        return ans;
        
    }
};