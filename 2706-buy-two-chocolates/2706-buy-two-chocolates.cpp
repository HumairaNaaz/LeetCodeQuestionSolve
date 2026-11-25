class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        sort(begin(prices),end(prices));
         int sum=prices[0]+prices[1];
       
            if(sum<=money){
                return money-sum;
            }
        
        return money;
        
    }
};