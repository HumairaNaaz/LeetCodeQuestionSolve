class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();

        vector<int> copies(n,0);
       

        for(int i=0;i<n;i++){
           
            int copy=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;

                if(items[j][0] % items[i][0]==0) copy++;
            }
            copies[i]=copy;
        }
        vector<vector<int>> t(n+1,vector<int>(budget+1,0));

            for(int i=1;i<=n;i++){
                int price=items[i-1][1];
                for(int b=0;b<=budget;b++){
                    
                    int take=0;

                if(price<=b){
                    take=1+copies[i-1]+t[i-1][b-price];
                    if(b >= 2 * price) {
                        take = max(take, 1 +
                                   t[i][b -price]);
                    }
                }
                
                
                int skip=t[i-1][b];
                t[i][b]=max(take,skip);

                }
            }
                
        return t[n][budget];
        
    }
};