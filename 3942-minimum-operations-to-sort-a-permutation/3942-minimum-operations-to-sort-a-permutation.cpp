class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int pos=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pos=i;
                break;
            }
        }
        bool left=true,right=true;
        for(int i=1;i<n;i++){
            if(nums[(pos+i)%n]!=i){
                left=false;
            }
             if(nums[(pos-i+n)%n]!=i){
                right=false;
            }
        }
        int ans=INT_MAX;
        if(left){
            ans =min(pos,n-pos+2);
        }
        if(right){
            ans =min(ans,min(pos+2,n-pos));
        }

        return ans==INT_MAX?-1:ans;

        
    }
};