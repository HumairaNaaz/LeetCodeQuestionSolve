class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        vector<int> count(26,0);
        int ans=0;
        while(j<n){
            count[s[j]-'a']++;
            while(count[s[j]-'a']>2){
                count[s[i]-'a']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
        }
        return ans;
        
    }
};