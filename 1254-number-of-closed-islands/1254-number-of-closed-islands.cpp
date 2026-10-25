class Solution {
public:
 int m,n;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r>=m || r<0 || c>=n || c<0) return false; //out of bound
        if(grid[r][c]==1){//water
            return true; //closed
        }
        grid[r][c]=1; // mark visited

        bool left_close=dfs(grid,r,c-1);
        bool right_close=dfs(grid,r,c+1);
        bool up_close=dfs(grid,r-1,c);
        bool down_close=dfs(grid,r+1,c);

        return left_close && right_close && up_close && down_close;

    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){ //land
                   if(dfs(grid,i,j)==true){
                    cnt++;
                   }
                }
            }
        }
        return cnt;
        
    }
};