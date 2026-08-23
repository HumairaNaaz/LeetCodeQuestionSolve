class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        if(n>m) return false;

        vector<int> s1_Freq(26,0);
        vector<int> s2_Freq(26,0);

        for(char &ch:s1){
            s1_Freq[ch-'a']++;
        }
        int i=0,j=0;
        while(j<m){
            s2_Freq[s2[j]-'a']++;

            //shrink
            if(j-i+1 > n){
                s2_Freq[s2[i]-'a']--;
                i++;
            }
            if(s1_Freq==s2_Freq){
                return true;
            }
            j++;
        }
        return false;
    }
};