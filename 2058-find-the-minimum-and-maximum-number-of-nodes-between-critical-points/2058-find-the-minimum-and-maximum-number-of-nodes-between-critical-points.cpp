/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        int first = -1;
        int prevCritical = -1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != NULL) {

            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // Distance between consecutive critical points
                if (prevCritical != -1) {
                    minDist = min(minDist, index - prevCritical);
                }

                prevCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Agar 2 se kam critical points hain
        if (first == -1 || first == prevCritical) {
            return {-1, -1};
        }

        // Maximum distance = first aur last critical point
        int maxDist = prevCritical - first;

        return {minDist, maxDist};
    }
};