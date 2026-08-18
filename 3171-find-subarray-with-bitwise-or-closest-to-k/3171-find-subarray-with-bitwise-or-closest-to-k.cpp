class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        int ans = INT_MAX;
        vector<int> prev;

        for (int num : nums) {

            vector<int> curr;

            curr.push_back(num);

            for (int x : prev) {

                int newOR = x | num;

                if (curr.back() != newOR) {
                    curr.push_back(newOR);
                }
            }

            for (int x : curr) {
                ans = min(ans, abs(x - k));
            }

            if (ans == 0)
                return 0;

            prev = curr;
        }

        return ans;
    }
};