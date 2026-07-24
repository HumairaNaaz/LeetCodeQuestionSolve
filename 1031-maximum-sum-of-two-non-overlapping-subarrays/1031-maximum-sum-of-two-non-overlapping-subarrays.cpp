class Solution {
public:

    // Returns maximum sum when window L comes before window M
    int helper(vector<int>& nums, int L, int M) {

        int n = nums.size();

        // Sum of first L elements
        int Lsum = 0;
        for(int i = 0; i < L; i++)
            Lsum += nums[i];

        int maxL = Lsum;

        // Sum of first M window after L
        int Msum = 0;
        for(int i = L; i < L + M; i++)
            Msum += nums[i];

        int ans = maxL + Msum;

        // Move both windows together
        for(int i = L + M; i < n; i++)
        {
            // Move L window by 1
            Lsum += nums[i - M] - nums[i - M - L];
            maxL = max(maxL, Lsum);

            // Move M window by 1
            Msum += nums[i] - nums[i - M];

            ans = max(ans, maxL + Msum);
        }

        return ans;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        return max(helper(nums, firstLen, secondLen),
                   helper(nums, secondLen, firstLen));
    }
};