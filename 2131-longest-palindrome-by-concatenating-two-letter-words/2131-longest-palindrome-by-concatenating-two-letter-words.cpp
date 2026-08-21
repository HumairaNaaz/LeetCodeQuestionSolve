class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        
        //frequency 
        for(string &word:words){
            freq[word]++;
        }

        bool centerUsed =false;
        int result=0;

        for(string &word:words){
            string rev=word;
            reverse(begin(rev),end(rev));

            // {ab ba}-> ab   ba
            if(rev!= word){
              if(freq[word]>0 && freq[rev]>0){
                freq[word]--;
                freq[rev]--;
                result +=4;
              }
            }
            else{ //{aa bb}-> bbaa  aabb
                if(freq[word]>=2){
                  freq[word] -=2;;
                  result +=4;
                }
                else if(freq[word]==1 && centerUsed==false){
                    freq[word]--;
                    result +=2;
                    centerUsed=true;

                }

            }
        }
        return result;
        
    }
};