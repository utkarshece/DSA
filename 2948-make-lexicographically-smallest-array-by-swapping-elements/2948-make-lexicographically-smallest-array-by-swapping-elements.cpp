class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int, int>> v;

        // value + original index
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // values ko sort karo
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            int j = i;

            // Same group find karo
            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Original indices collect karo
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
            }

            // Original positions sort karo
            sort(indices.begin(), indices.end());

            // Group ke sorted values ko
            // sorted original positions par daalo
            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};