class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        int cnt[26] = {};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {

            if (cnt[i] % 2 == 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters for left half
        int half[26];

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int m = n / 2;

        // ------------------------------------------------
        // STEP 1:
        // Try to make left half exactly equal to target's
        // left half.
        // ------------------------------------------------

        int temp[26];

        for (int i = 0; i < 26; i++) {
            temp[i] = half[i];
        }

        string left = "";
        bool possible = true;

        for (int i = 0; i < m; i++) {

            int x = target[i] - 'a';

            if (temp[x] == 0) {
                possible = false;
                break;
            }

            left += target[i];
            temp[x]--;
        }

        if (possible) {

            string ans = left;

            if (n % 2 == 1) {
                ans += mid;
            }

            string right = left;
            reverse(right.begin(), right.end());

            ans += right;

            // Equal left half can still make the palindrome
            // greater because of middle/right half.
            if (ans > target) {
                return ans;
            }
        }

        // ------------------------------------------------
        // STEP 2:
        // Left half equal nahi bana ya usse answer nahi mila.
        // Ab right se left jaakar ek position ko bigger karenge.
        // ------------------------------------------------

        for (int pos = m - 1; pos >= 0; pos--) {

            int temp2[26];

            for (int i = 0; i < 26; i++) {
                temp2[i] = half[i];
            }

            bool ok = true;

            // Target ka prefix same rakho
            for (int i = 0; i < pos; i++) {

                int x = target[i] - 'a';

                if (temp2[x] == 0) {
                    ok = false;
                    break;
                }

                temp2[x]--;
            }

            if (!ok) {
                continue;
            }

            // target[pos] se just bada smallest character
            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (temp2[c] == 0) {
                    continue;
                }

                string newLeft = target.substr(0, pos);

                newLeft += char('a' + c);

                temp2[c]--;

                // Remaining characters smallest order me
                for (int j = 0; j < 26; j++) {

                    while (temp2[j] > 0) {
                        newLeft += char('a' + j);
                        temp2[j]--;
                    }
                }

                // Complete palindrome
                string ans = newLeft;

                if (n % 2 == 1) {
                    ans += mid;
                }

                string right = newLeft;
                reverse(right.begin(), right.end());

                ans += right;

                return ans;
            }
        }

        return "";
    }
};