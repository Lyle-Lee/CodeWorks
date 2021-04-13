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
    void dfs(TreeNode* root, int& pre, int& res) {
        if (root == nullptr) return;
        dfs(root->left, pre, res);
        if (pre == -1) { // the smallest number in BST
            pre = root->val;
        } else {
            res = min(res, root->val - pre); // \min_{i = 0}^{n-2} nums[i+1] - nums[i]
            pre = root->val;
        }
        dfs(root->right, pre, res);
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1, result = INT_MAX;
        dfs(root, prev, result);
        return result;
    }
};
