class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = s[i...j] palindrome hai ya nahi
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Length 1
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Length 2 se n tak
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2) {
                        pal[i][j] = true;
                    }
                    else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] = first i characters ka maximum answer
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // s[i-1] ko use nahi karte
            dp[i] = dp[i - 1];

            // substring ka start
            for (int j = 0; j <= i - k; j++) {

                // s[j...i-1] palindrome hai
                if (pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};