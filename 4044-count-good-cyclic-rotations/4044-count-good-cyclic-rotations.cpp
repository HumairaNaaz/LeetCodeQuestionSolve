class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();

        int firstHalf=n/2;
        int lastHalf=n/2;
        long long sumFirst=0;
        long long sumLast=0;

        for(int i=0;i<firstHalf;i++){
            sumFirst +=nums[i];
        }
        for(int i=firstHalf;i<n;i++){
            sumLast +=nums[i];
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(sumFirst>sumLast){
                ans++;
            }
            //rotation
            sumFirst=sumFirst-nums[i]+nums[(i+firstHalf)%n];
            sumLast=sumLast-nums[(i+lastHalf)%n]+nums[i];
        }
        return ans;
        
    }
};