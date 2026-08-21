class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    bool check(long long x, vector<int>& coins, int k) {

        long long count = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {

            long long LCM = 1;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    LCM = lcm(LCM, coins[i]);

                    if (LCM > x)
                        break;
                }
            }

            int bits = __builtin_popcount(mask);

            if (bits % 2 == 1)
                count += x / LCM;
            else
                count -= x / LCM;
        }

        return count >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * k * coins[0];

        for (int coin : coins) {
            high = min(high, 1LL * k * coin);
        }

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (check(mid, coins, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};