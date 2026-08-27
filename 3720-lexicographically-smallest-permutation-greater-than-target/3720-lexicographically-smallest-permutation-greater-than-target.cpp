class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int cnt[26] = {};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        int n = s.size();

        // Right se ek position par target se bada character lagane ki try
        for (int i = n - 1; i >= 0; i--) {

            // target ke 0...i-1 characters same rakhne hain
            int temp[26];

            for (int j = 0; j < 26; j++) {
                temp[j] = cnt[j];
            }

            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            // Position i par target[i] se bada smallest character
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (temp[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    temp[c]--;

                    // Baaki characters smallest order me
                    for (int j = 0; j < 26; j++) {
                        while (temp[j] > 0) {
                            ans += char('a' + j);
                            temp[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};