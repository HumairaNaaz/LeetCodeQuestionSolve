class Solution {
public:
    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum +=(num%10);
            num =num/10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<int> aftersorted(nums);
        auto lambda =[&](int num1,int num2){
            int num1digitSum=getDigitSum(num1);
            int num2digitSum=getDigitSum(num2);
            if(num1digitSum!=num2digitSum){
                return num1digitSum<num2digitSum;
            }
            return num1<num2;
        };

        sort(begin(aftersorted),end(aftersorted),lambda);

        unordered_map<int,int> valToIndx;
        for(int i=0;i<n;i++){
            valToIndx[nums[i]]=i;
        }
        int swapcnt=0;
        for(int i=0;i<n;i++){
            int expectedVal=aftersorted[i];
            int currVal=nums[i];
            if(expectedVal==currVal) continue;
            int idx=valToIndx[expectedVal];
            nums[i]=expectedVal;
            nums[idx]=currVal;

            valToIndx[expectedVal]=i;
            valToIndx[currVal]=idx;
            swapcnt++;
        }
        return swapcnt;
        
    }
};