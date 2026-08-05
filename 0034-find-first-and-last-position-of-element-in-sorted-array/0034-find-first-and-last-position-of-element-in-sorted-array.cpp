class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        
         int F_occ=-1;
         int L_occ=-1;
       
        int l=0,r=n-1;
       //first occurence 
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                F_occ=mid;
                r=mid-1;
           
            } 
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        
        //last Occurence
         l = 0;
        r = n-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                L_occ=mid;
                l=mid+1;
           
            } 
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return {F_occ,L_occ};
    }
};