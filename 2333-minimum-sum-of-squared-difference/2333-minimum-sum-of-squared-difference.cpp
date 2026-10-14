class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long k = 1LL * k1 + k2;

        for (int i = 0; i < nums1.size(); i++) {
            diff.push_back(abs(nums1[i] - nums2[i]));
        }

        sort(diff.rbegin(), diff.rend());

        int n = diff.size();

        for (int i = 0; i < n; i++) {
            long long cnt = i + 1;
            long long need = cnt * diff[i];

            if (i + 1 < n) {
                need -= 1LL * (i + 1) * diff[i + 1];
            }

            if (k >= need) {
                k -= need;
                diff[i] = (i + 1 < n) ? diff[i + 1] : 0;
            } else {
                long long level = diff[i] - k / cnt;
                long long rem = k % cnt;

                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    long long x = level;
                    if (j < rem) x--;
                    ans += x * x;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += 1LL * diff[j] * diff[j];
                }

                return ans;
            }
        }

        return 0;
    }
};