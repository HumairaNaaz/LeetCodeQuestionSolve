class Solution {
public:
    int m,n;
    bool t[101][101][201];
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        if((m+n-1)%2==1){
            return false;
        }
        if(grid[0][0] !='(' || grid[m-1][n-1] !=')'){
            return false;
        }
         
         for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int openCnt=0;openCnt<=i+j+1;openCnt++){
                    if(i==m-1 && j==n-1){
                        t[i][j][openCnt]=(openCnt==0);
                        continue;
                    }
                    t[i][j][openCnt]=false;

                    //mode down
                    if(i+1<m){
                        int newCnt=(grid[i+1][j]=='(') ? openCnt+1 : openCnt-1;
                        if(newCnt >=0 && t[i+1][j][newCnt]){
                            t[i][j][openCnt]=true;
                        }
                    }

                    //mode right 
                     if(j+1<n){
                        int newCnt=(grid[i][j+1]=='(') ? openCnt+1 : openCnt-1;
                        if(newCnt >=0 && t[i][j+1][newCnt]){
                            t[i][j][openCnt]=true;
                        }
                    }
                }
            }
         }
         return t[0][0][1];
        
    }
};