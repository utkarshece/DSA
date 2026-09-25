class Solution {
public:

    set<string> merge(set<string> a, set<string> b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        stack<set<string>> st;

        // Current set
        set<string> cur = {""};

        // Operators:
        // '+' means union
        // '*' means concatenation

        stack<char> ops;

        int i = 0;

        while (i < expression.size()) {

            char ch = expression[i];

            // Normal character
            if (ch >= 'a' && ch <= 'z') {

                set<string> temp;

                temp.insert(string(1, ch));

                // Character ko current expressions ke saath concatenate karo
                cur = merge(cur, temp);

                i++;
            }

            // Opening brace
            else if (ch == '{') {

                // Current expression save karo
                st.push(cur);

                // Operator save karna baad me zaroori hoga
                ops.push('{');

                // New expression start
                cur = {""};

                i++;
            }

            // Comma = UNION
            else if (ch == ',') {

                // Current part save karo
                st.push(cur);

                // Union ke liye empty current
                cur = {""};

                ops.push(',');

                i++;
            }

            // Closing brace
            else if (ch == '}') {

                // Current part
                set<string> right = cur;

                // Jab tak matching '{' nahi milta
                set<string> all;

                while (!ops.empty() && ops.top() == ',') {

                    ops.pop();

                    set<string> left = st.top();
                    st.pop();

                    for (string s : left)
                        all.insert(s);

                    for (string s : right)
                        all.insert(s);
                }

                if (!ops.empty() && ops.top() == '{') {
                    ops.pop();
                }

                // Agar comma nahi tha
                if (all.empty()) {
                    all = right;
                }

                // Braces ke bahar jo expression tha
                if (!st.empty()) {

                    set<string> outside = st.top();
                    st.pop();

                    cur = merge(outside, all);

                } else {
                    cur = all;
                }

                i++;
            }
        }

        return vector<string>(cur.begin(), cur.end());
    }
};