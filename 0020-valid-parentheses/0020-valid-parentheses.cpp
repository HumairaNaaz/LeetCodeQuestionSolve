class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis;
        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){
                parenthesis.push(c);
            }
            else{
                if(parenthesis.empty()) return false;
                char top=parenthesis.top();
                parenthesis.pop();
                if(c==')'&& top!='(' || c==']'&& top!='[' || c=='}'&& top!='{' ){
                    return false;
                }
            }
        }
        return parenthesis.empty();

    }
};