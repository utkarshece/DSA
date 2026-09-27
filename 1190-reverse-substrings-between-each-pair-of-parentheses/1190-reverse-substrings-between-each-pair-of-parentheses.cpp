class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                // Current string save karo
                st.push(curr);
                curr = "";
            }

            else if (ch == ')') {
                // Bracket ke andar wali string reverse
                reverse(curr.begin(), curr.end());

                // Previous string ke saath jodo
                curr = st.top() + curr;
                st.pop();
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};