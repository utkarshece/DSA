class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freeCnt(n, 0);

        // Count free items for each item type
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        // 0/1 Knapsack
        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = freeCnt[i] + 1;

            for (int j = budget; j >= price; j--) {
                if (dp[j - price] != NEG) {
                    dp[j] = max(dp[j], dp[j - price] + gain);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            if (dp[i] != NEG) {
                ans = max(ans, dp[i] + (budget - i) / minPrice);
            }
        }

        return ans;
    }
};