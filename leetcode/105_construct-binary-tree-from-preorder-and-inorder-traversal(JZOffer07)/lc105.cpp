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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int idxPre = 1, idxIn = 0;
        while (idxPre < n) {
            TreeNode *cur = stk.top();
            if (cur->val != inorder[idxIn]) {
                cur->left = new TreeNode(preorder[idxPre]);
                stk.push(cur->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[idxIn]) {
                    cur = stk.top();
                    stk.pop();
                    ++idxIn;
                }
                cur->right = new TreeNode(preorder[idxPre]);
                stk.push(cur->right);
            }
            ++idxPre;
        }
        return root;
    }
};
