class Solution {
public:
    int smallestNumber(int n, int t) {
        int current =n;
        
        while(true){
          n=current;
          int mult=1;
          
          while(n>0){
            int digit=n%10;
            mult=digit*mult;
            n=n/10;
          }
            if(mult %t==0){
               return current;

            }

        current++;
        }
        
    }
};