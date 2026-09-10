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
    int matchingNodesCount = 0;

    // Helper function returning {subtree_sum, subtree_count}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int currentSum = left.first + right.first + root->val;
        int currentCount = left.second + right.second + 1;

        if (currentSum / currentCount == root->val) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodesCount;
    }
};