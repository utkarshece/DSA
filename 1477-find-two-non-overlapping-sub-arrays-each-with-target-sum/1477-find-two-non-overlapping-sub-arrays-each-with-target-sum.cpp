class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const int INF = 1e9;

        // best[i] = first i elements me target-sum
        // subarray ki minimum length
        vector<int> best(n + 1, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Sum target se bada ho gaya
            // to left se elements remove karo
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Current window ka sum target hai
            if (sum == target) {

                int len = right - left + 1;

                // Current subarray se pehle wala
                // shortest subarray
                if (left > 0 && best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }

                // Current position tak ka best
                best[right + 1] = min(best[right], len);
            }
            else {
                best[right + 1] = best[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};