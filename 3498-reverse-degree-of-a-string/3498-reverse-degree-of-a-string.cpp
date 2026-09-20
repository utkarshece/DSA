class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            // Reverse alphabet value
            int value = 26 - (s[i] - 'a');

            // i + 1 because position 1-indexed hai
            ans += value * (i + 1);
        }

        return ans;
    }
};