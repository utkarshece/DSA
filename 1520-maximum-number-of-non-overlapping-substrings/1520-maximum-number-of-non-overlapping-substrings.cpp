class Solution {
public:

    int getRight(string &s, int start,
                 vector<int> &first,
                 vector<int> &last) {

        int end = last[s[start] - 'a'];

        for (int i = start; i <= end; i++) {

            int ch = s[i] - 'a';

            // Is character ki occurrence
            // start se bhi pehle hai
            if (first[ch] < start)
                return -1;

            // Is character ki last occurrence
            // interval ko aur bada sakti hai
            end = max(end, last[ch]);
        }

        return end;
    }

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First aur last occurrence
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        // Har character ke first occurrence se
        // ek possible interval banao
        for (int i = 0; i < n; i++) {

            int ch = s[i] - 'a';

            // Sirf first occurrence se start karenge
            if (i != first[ch])
                continue;

            int right = getRight(s, i, first, last);

            if (right != -1) {
                intervals.push_back({right, i});
            }
        }

        // Smallest right endpoint first
        sort(intervals.begin(), intervals.end());

        vector<string> ans;

        int previousEnd = -1;

        for (auto interval : intervals) {

            int right = interval.first;
            int left = interval.second;

            // Non-overlapping
            if (left > previousEnd) {

                ans.push_back(s.substr(left, right - left + 1));

                previousEnd = right;
            }
        }

        return ans;
    }
};