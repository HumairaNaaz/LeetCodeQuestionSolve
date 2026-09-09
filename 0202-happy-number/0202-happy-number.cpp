class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1) {
            if(seen.count(n)){
                return false;
            }
            seen.insert(n);
            int result = 0;

            while (n > 0) {
                int digit = n % 10;
                result += digit * digit;
                n = n / 10;
            }
            n=result;
        }
        return true;
    }
};