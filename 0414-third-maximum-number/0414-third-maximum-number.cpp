class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long long first=LLONG_MIN;
        long long sec=LLONG_MIN;
        long long third=LLONG_MIN;

        for(int x:nums){
             if(x==first || x==sec || x==third){
                continue;
             }

             if(x>first){
                third=sec;
                sec=first;
                first=x;  //3
             }
             else if(x>sec){
                third=sec;
                sec=x;
             }
             else if(x>third){
                third=x;
             }

        }
        if(third==LLONG_MIN){
            return first;
        }

       return third; 
    }
};