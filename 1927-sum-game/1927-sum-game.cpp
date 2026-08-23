class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int sum1 = 0;
        int sum2 = 0;

        int q1 = 0;
        int q2 = 0;

        for (int i = 0; i < n / 2; i++) {

            if (num[i] == '?')
                q1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {

            if (num[i] == '?')
                q2++;
            else
                sum2 += num[i] - '0';
        }

        if ((q1 + q2) % 2 == 1)
            return true;

        return sum1 - sum2 != 9 * (q2 - q1) / 2;
    }
};