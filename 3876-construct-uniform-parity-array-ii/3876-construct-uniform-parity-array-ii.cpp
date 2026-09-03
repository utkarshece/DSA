class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;

        // minimum element find karo
        for (int x : nums1) {
            mn = min(mn, x);
        }

        // minimum odd hai
        if (mn % 2 == 1) {
            return true;
        }

        // minimum even hai
        // ab agar koi odd mila -> false
        for (int x : nums1) {
            if (x % 2 == 1) {
                return false;
            }
        }

        // saare even hain
        return true;
    }
};