class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Minimum aur maximum ke index find karo
        for (int i = 0; i < n; i++) {

            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Dono indexes ko order me rakho
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Case 1: dono left se
        int case1 = right + 1;

        // Case 2: dono right se
        int case2 = n - left;

        // Case 3: left wale ko left se,
        // right wale ko right se
        int case3 = left + 1 + n - right;

        return min({case1, case2, case3});
    }
};