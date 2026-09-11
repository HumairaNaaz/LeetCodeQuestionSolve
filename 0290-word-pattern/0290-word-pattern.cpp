class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp1;
        map<string,char> mp2;

        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }
         
         if(pattern.size() !=words.size()){
            return false;
         }

        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string w=words[i];

            //ch mapping 
            if(mp1.count(ch)){
                if(mp1[ch]!= w){
                    return false;
                }
            }

            //string 
            if(mp2.count(w)){
                if(mp2[w]!= ch){
                    return false;
                }
            }
            mp1[ch]=w;
            mp2[w]=ch;
        }

      return true; 
        
    }
};