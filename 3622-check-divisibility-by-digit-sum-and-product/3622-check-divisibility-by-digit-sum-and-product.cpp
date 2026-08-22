class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int temp=n;
        while(n>0){
        int digit =n%10;
        sum=sum+digit;
        product=digit*product;
        n=n/10;
        }
        int ans=sum+product;

        if(temp%ans==0){
            return true;
        }
        else{
          return false;
        } 

        
    }
};