class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {

        int n=capacity.size();
        vector<long long> prefix(n);
        prefix[0]=capacity[0];
       
       //prefixsum
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+capacity[i];
        }
        map<pair<long long,long long>,long long> mp;

        long long ans=0;

        for(int r=2;r<n;r++){
            int l=r-2;

            //store
            mp[{prefix[l],capacity[l]}]++;

            //find target
            long long target=prefix[r]-2LL*capacity[r];

            //search
            ans =ans+mp[{target,capacity[r]}];
        }
        return ans;
        
    }
};