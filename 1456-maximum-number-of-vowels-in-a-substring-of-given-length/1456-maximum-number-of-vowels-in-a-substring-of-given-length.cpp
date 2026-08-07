class Solution {
public:
    int maxVowels(string s, int k) {
      int n=s.size();
      int i=0,j=0;
      int maxVowel=0,cnt=0;

      while(j<n){
       if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
           cnt++;
        }
        if(j-i+1 ==k){
            maxVowel=max(maxVowel,cnt);
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt--;
            }
            i++;
        }
        j++;
      }
      return maxVowel;
    }
};