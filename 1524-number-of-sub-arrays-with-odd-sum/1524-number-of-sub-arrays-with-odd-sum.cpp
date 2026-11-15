class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        long long result=0;
        long long evenCnt=1;
        long long oddCnt=0;
        long long prefixSum=0;
        for(int num:arr){
            prefixSum +=num;

            if(prefixSum%2==0){
                result +=oddCnt;
                evenCnt++;
            }
            else{
                result +=evenCnt;
                oddCnt++;
            }
            result %=MOD;
        }

        return result;
    }
};