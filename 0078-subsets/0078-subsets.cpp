class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int n;
    void solve(int idx , vector<int>& nums){
        if(idx==n){
            result.push_back(temp);
            return;
        }
            //1. take
            temp.push_back(nums[idx]);
            solve(idx+1 , nums);

            //2 backtracking
            temp.pop_back();

            //3. dont take
            solve(idx+1 , nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        solve(0,nums);
        return result; 
    }
    
};