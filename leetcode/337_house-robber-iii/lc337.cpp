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
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        auto ans = dfs(root);
        return ans.first;
    }

    pair<int, int> dfs(TreeNode* node) {
        if (!node->left && !node->right) return {node->val, 0}; // {contain, not contain}
        pair<int, int> res = {node->val, 0};
        if (node->left) {
            auto leftpart = dfs(node->left);
            res.first += leftpart.second;
            res.second += leftpart.first;
        }
        if (node->right) {
            auto rightpart = dfs(node->right);
            res.first += rightpart.second;
            res.second += rightpart.first;
        }
        res.first = max(res.first, res.second);
        return res;
    }
};
