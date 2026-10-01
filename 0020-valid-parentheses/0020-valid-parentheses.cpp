class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing bracket
            else {

                // Agar opening bracket hi nahi hai
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Matching check
                if (ch == ')' && top != '(')
                    return false;

                if (ch == '}' && top != '{')
                    return false;

                if (ch == ']' && top != '[')
                    return false;
            }
        }

        // Stack empty hai to sab brackets match ho gaye
        return st.empty();
    }
};