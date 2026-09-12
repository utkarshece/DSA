class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // [start, end, weight, original_index]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // starts store karo
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        // dp[i][k] = i se aage maximum score
        // k = kitne intervals aur choose kar sakte hain
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: current interval skip
                auto best = dp[i + 1][k];

                // Option 2: current interval choose
                long long end = a[i][1];

                int next = upper_bound(
                    starts.begin(),
                    starts.end(),
                    end
                ) - starts.begin();

                long long score = a[i][2] + dp[next][k - 1].first;

                vector<int> ids = dp[next][k - 1].second;
                ids.push_back((int)a[i][3]);

                sort(ids.begin(), ids.end());

                if (score > best.first ||
                    (score == best.first && ids < best.second)) {

                    best = {score, ids};
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].second;
    }
};