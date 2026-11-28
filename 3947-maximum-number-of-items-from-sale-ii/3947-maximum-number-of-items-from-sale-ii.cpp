
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Count frequency of each factor
        for(auto &item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Count how many items have factors divisible by i
        vector<int> gain(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        for(auto &item : items) {
            int factor = item[0];
            int price = item[1];

            // Double-value purchases are not beneficial
            // if price >= 2 * minPrice
            if(2LL * minPrice <= price)
                break;

            int cnt = gain[factor];

            if(cnt <= 0) continue;

            long long take = min((long long)cnt, remaining / price);

            ans += take * 2;
            remaining -= take * price;
        }

        // Spend remaining budget on cheapest items
        ans += remaining / minPrice;

        return (int)ans;
    }
};
