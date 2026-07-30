class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int diffrences=0;
            int maxfreq=0;
            vector<int> freq(26,0);

            for(int j=i;j<n;j++){
                int indx=s[j]-'a';

                if(freq[indx]==0)
                    diffrences++;
                
                freq[indx]++;
               maxfreq=max(maxfreq,freq[indx]);
                int len=j-i+1;
                if(diffrences*maxfreq==len)
                {
                    ans=max(ans,len);
                }

            }

        }
        return ans;
        
    }
};