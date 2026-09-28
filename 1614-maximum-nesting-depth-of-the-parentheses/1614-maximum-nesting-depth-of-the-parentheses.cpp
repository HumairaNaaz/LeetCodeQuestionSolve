class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        int n=s.size();
        int result=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                st.pop();
            }
            result=max(result,(int)st.size());
        }
        return result;
    }
};