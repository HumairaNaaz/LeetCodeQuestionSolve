class Solution {
public:
    int maxProduct(int n) {
        vector<int> digit;
        while(n>0){
           digit.push_back(n%10);
           n=n/10;
        }

        int m=digit.size();
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
               int product=digit[i]*digit[j];
               maxi=max(maxi,product);
            }
        }
        return maxi;
    }
};