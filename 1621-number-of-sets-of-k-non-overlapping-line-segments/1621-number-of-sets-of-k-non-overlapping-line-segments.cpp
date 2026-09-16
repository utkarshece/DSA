class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> open(n, vector<long long>(k + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                // Kuch nahi karna / previous ways carry
                dp[i][j] = dp[i - 1][j];

                if (j > 0) {
                    // New segment start
                    open[i][j] = dp[i - 1][j - 1];

                    // Existing segment continue
                    open[i][j] =
                        (open[i][j] + open[i - 1][j]) % MOD;

                    // Segment finish/available
                    dp[i][j] =
                        (dp[i][j] + open[i][j]) % MOD;
                }
            }
        }

        return dp[n - 1][k];
    }
};