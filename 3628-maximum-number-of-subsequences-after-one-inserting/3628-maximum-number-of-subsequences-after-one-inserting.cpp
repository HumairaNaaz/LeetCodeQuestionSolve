class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        // Count existing LCT subsequences
        long long L = 0, LC = 0, LCT = 0;

        for (char ch : s) {
            if (ch == 'L')
                L++;
            else if (ch == 'C')
                LC += L;
            else if (ch == 'T')
                LCT += LC;
        }

        // ---------------- Gain by inserting L ----------------
        long long T = 0, CT = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T')
                T++;
            else if (s[i] == 'C')
                CT += T;
        }

        long long gainL = CT;

        // ---------------- Gain by inserting T ----------------
        long long gainT = LC;

        // ---------------- Gain by inserting C ----------------
        vector<long long> suffixT(n + 1, 0);

        // suffixT[i] = number of T's from index i to end
        for (int i = n - 1; i >= 0; i--) {
            suffixT[i] = suffixT[i + 1];
            if (s[i] == 'T')
                suffixT[i]++;
        }

        long long gainC = 0;
        L = 0;

        // Try inserting C at every position
        for (int i = 0; i <= n; i++) {
            gainC = max(gainC, L * suffixT[i]);

            if (i < n && s[i] == 'L')
                L++;
        }

        return LCT + max({gainL, gainC, gainT});
    }
};