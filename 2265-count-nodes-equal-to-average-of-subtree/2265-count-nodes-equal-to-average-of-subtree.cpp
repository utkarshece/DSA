/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> dfs(TreeNode* root, int &ans) {

        // Empty node
        if (root == NULL) {
            return {0, 0};
        }

        // Left subtree
        pair<int, int> left = dfs(root->left, ans);

        // Right subtree
        pair<int, int> right = dfs(root->right, ans);

        // Current subtree ka sum
        int sum = left.first + right.first + root->val;

        // Current subtree me total nodes
        int count = left.second + right.second + 1;

        // Average check
        if (sum / count == root->val) {
            ans++;
        }

        // Parent ko sum aur count return karo
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};