class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n=s.size();
        int i=0,j=0,countZero=0,countOnes=0;
        int result=0;


        while(j<n){
            if(s[j]=='0'){
                countZero++;
            }
            else countOnes++;

            while(countZero > k && countOnes> k) { //unsatisfied window keep shrink
                if(s[i]=='0'){
                    countZero--;
                }
                else countOnes--;
                i++;                
            }
            result += (j-i+1);
            j++;
        }
        return result;
        
    }
};