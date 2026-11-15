class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;
        int sum = 0;

        for (int num : arr) {
            sum += num;

            if (sum % 2 == 0) {
                ans = (ans + odd) % mod;
                even++;
            }
            else {
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
};