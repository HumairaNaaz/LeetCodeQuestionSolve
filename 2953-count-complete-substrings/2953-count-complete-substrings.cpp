class Solution {
public:
    int solve(int start,int end,string &word,int k){
        int result=0;

        //1-unique char,2 u nique char
        for(int unique_char=1;unique_char<=26 && unique_char*k<=end-start+1;unique_char++){
             vector<int> count(26,0);
             int Goodboy=0;
             
             //start sliding process
             int i=start;
             int windowSize=unique_char*k;
             for(int j=start;j<=end;j++){
                char ch=word[j];
                count[ch-'a']++;
                if(count[ch-'a']==k) Goodboy++;
                else if(count[ch-'a']==k+1) Goodboy--;

                //time to slide i++
                if(j-i+1>windowSize){
                if(count[word[i]-'a']==k) Goodboy--;
                else if(count[word[i]-'a']==k+1) Goodboy++;

                count[word[i]-'a']--;
                i++;
                }
                if(j - i + 1 == windowSize  && Goodboy==unique_char){
                       result++;
                }

             }

        }
        return result;
    }
    int countCompleteSubstrings(string word, int k) {
        int n=word.size();
        //dividing 
        int last=0,result=0;

        for(int i=1;i<=n;i++){
            if(i==n || abs(word[i]-word[i-1])>2){
                result= result+solve(last,i-1,word,k);
                last=i;
            }
        }
        return result;

    }
};