class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        unordered_map<string,string> mp;
        for(auto& vec:knowledge){
            mp[vec[0]]=vec[1];
        }
        int i=0;
        string result="";

        while(i<n){
            if(isalpha(s[i])){
                result.push_back(s[i]);
            }
            else{
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                result +=mp.count(temp)?mp[temp]: "?";
            }
            i++;
        }
        return result;

    }
};