class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> ans;
        //last occurence of elemnt
        vector<int> mp(26,-1);

        //calc  last occurence  like a=8,b=5....
        for(int i=0;i<n;i++){
            int indx=s[i]-'a';
            mp[indx]=i;
        }

        int i=0,start=0,end=0;

        while(i<n){
            end=max(end,mp[s[i]-'a']);

            if(i==end){
                ans.push_back(end-start+1);

                start=end+1;
            }
            i++;
        }

        return ans;
        
    }
};