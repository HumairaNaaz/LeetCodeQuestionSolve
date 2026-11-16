class Solution {
public:
    string digitSum(string s, int k) {
       while(s.length()>k){
         string ans="";
         for(int i=0;i<s.length();i +=k){
            int sum=0;
            //cal sum of each group
            for(int j=i;j<s.length()&& j<i+k;j++){
                sum +=s[j]-'0';
            }

            //convert int sum to string
            ans +=to_string(sum);
         }
         //update string for next round
         s=ans;
       }
       return s;
        
    }
};