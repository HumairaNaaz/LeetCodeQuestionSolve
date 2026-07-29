class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26);
     //freq of 1st word i=0
            for(char ch: words[0]){
                common[ch-'a']++;
            }

     // freq of remaining to compare
            for(int i=1;i<words.size();i++){

                vector<int> freq(26,0);
                //2nd word ka freq
                for(char ch:words[i]){
                    freq[ch-'a']++;
                }

                //min of both 1st and 2nd word or 3rd so on

                for(int j=0;j<26;j++){
                    common[j]=min(common[j],freq[j]);
                }

            }  

        //ans build
        vector<string> ans;
        for(int i=0;i<26;i++){

            while(common[i]>0){
               ans.push_back(string(1,'a'+i));
               common[i]--;
            }
        }

       return ans;
        
    }
};