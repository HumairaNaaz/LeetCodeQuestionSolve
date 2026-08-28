class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int cnt_a=0;
        int cnt_b=0;
        int cnt_c=0;

         for(char &ch:s){
            if(ch=='a'){
                cnt_a++;
            }
            else if(ch=='b'){
                cnt_b++;
            }
            else if(ch=='c'){
                cnt_c++;
            }

         }

         if(cnt_a<k || cnt_b<k || cnt_c<k){
              return -1;
         }

         int i=0,j=0;
         int notDeletedWindowSize=0;

         while(j<n){
            if(s[j]=='a'){
                cnt_a--;
            }
            else if(s[j]=='b'){
                cnt_b--;
            }
            else if(s[j]=='c'){
                cnt_c--;
            }

            while(i<=j && (cnt_a <k || cnt_b <k || cnt_c <k)){
                if(s[i]=='a'){
                cnt_a++;
            }
            else if(s[i]=='b'){
                cnt_b++;
            }
            else if(s[i]=='c'){
                cnt_c++;
            }
            i++;
            }
            notDeletedWindowSize=max(notDeletedWindowSize,j-i+1);
            j++;
         }
         return n-notDeletedWindowSize; //min
        
    }
};