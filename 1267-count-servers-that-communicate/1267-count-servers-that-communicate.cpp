class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> indexColCnt(n,0);
        vector<int> indexRowCnt(m,0);

        //preprocessing
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    indexColCnt[col] +=1;
                    indexRowCnt[row] +=1;
                }
            }
        }
        
        int ResultServer=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && (indexColCnt[col] >1 || indexRowCnt[row]>1)){
                    ResultServer++;
                }
            }
        }
        return ResultServer;
        
    }
};