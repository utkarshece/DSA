class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        map<pair<int, int>, int> mp;

        int ans = 0;

        // img1 ke har 1 ko dekho
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1) {

                    // img2 ke har 1 ko dekho
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {

                            if (img2[x][y] == 1) {

                                int dx = x - i;
                                int dy = y - j;

                                mp[{dx, dy}]++;

                                ans = max(ans, mp[{dx, dy}]);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};