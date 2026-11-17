class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // Find all divisors
        vector<vector<int>> factors(n + 1);

        for (int d = 1; d < n; d++) {
            for (int i = d * 2; i <= n; i += d) {
                factors[i].push_back(d);
            }
        }

        // cost[i][j] = changes needed for substring s[i...j]
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = n;

                for (int d : factors[len]) {
                    int changes = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;

                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        // DP
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));

        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                for (int l = i + 1; l < n; l++) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i][l] + dp[l + 1][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};