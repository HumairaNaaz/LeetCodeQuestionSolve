class Solution {
public:
    int beststartingPoint(string &word,int n){
        int i=0;   //best Starting Point
        int j=1;  //keep moving to find best Starting Point

        while(j<n){
            int k=0;
            //skipping =equal  char
            while(j+k<n && word[j+k]==word[i+k]){
               k++;
            }

            if(j+k<n && word[j+k] > word[i+k]){
                i=j; //updating best starting point
                j=j+1;
            }
            else {
                j=j+k+1;
            }
        }
        return i;
    }

    string answerString(string word, int numFriends) {
        int n=word.size();
       
        if(numFriends==1) return word;
      
       int i=beststartingPoint(word,n);
       int longestPossible=n-(numFriends-1);
       int canTakePossible=min(longestPossible,n-i);

       return word.substr(i,canTakePossible);
    }
};