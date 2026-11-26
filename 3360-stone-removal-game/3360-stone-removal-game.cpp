class Solution {
public:
    bool canAliceWin(int n) {
        int stone=10;
        bool alice=true;

        while(n>=stone){
            n=n-stone; //12-10=2
            stone--;
            alice =!alice; //swices to false
            
        } 
        return !alice;
        
    }
};