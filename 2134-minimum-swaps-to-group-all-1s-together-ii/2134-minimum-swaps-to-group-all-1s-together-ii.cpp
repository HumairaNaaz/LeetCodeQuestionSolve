class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(2*n);
        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n]; //{0 1 1,0}-> {0 1 1 0 0 1 1 0}
        }

        int totalOnes=accumulate(begin(nums),end(nums),0); 
            //window size containing all ones we need
        int currOnes=0;
        int maxOnes=0;
        int i=0,j=0;
        while(j<2*n){
            if(nums[j%n]==1){
                   currOnes++;
            }
            if(j-i+1 >totalOnes){
                currOnes -=nums[i%n];
                i++;
            }
            maxOnes=max(maxOnes,currOnes);
            j++;
        }

      return totalOnes-maxOnes;
        
    }
};