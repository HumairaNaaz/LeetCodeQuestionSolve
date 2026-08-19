class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> count;
        //subarray create
        for(int i=0;i<=n-k;i++){
            set<int> s;
            for(int j=i;j<i+k;j++){
                 s.insert(nums[j]);
            }
            //count subarray
            for(int x:s){
                count[x]++;
            }
        }
        int ans=-1;
        for(auto it:count){
            if(it.second==1){
                ans=max(ans,it.first);
            }

        }
        return ans;

        
    }
};