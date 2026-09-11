class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        set<int> st;

        int n = digits.size();

        for (int i = 0; i < n; i++) {

            // Hundreds digit 0 nahi ho sakta
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; j++) {

                // Same digit/index dobara use nahi karna
                if (j == i)
                    continue;

                for (int k = 0; k < n; k++) {

                    // Same index use nahi karna
                    if (k == i || k == j)
                        continue;

                    // Last digit even honi chahiye
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};