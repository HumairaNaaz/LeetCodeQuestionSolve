class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else {open--;}

            if(i>0 && s[i]==')' && s[i-1]=='(') {
                close += (1 << open);
            }
        }
        return close;
      
    }
};