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
    string tree2str(TreeNode* root) {
        string ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur == nullptr) ans += ')';
            else {
                ans += cur == root ? to_string(cur->val) : '(' + to_string(cur->val);
                if (cur != root) stk.push(nullptr);
                if (cur->right) stk.push(cur->right);
                if (cur->left) stk.push(cur->left);
                else if (cur->right) ans += "()";
            }
        }
        return ans;
    }
};
