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
    bool isCousins(TreeNode* root, int x, int y) {
        int k = 0;
        int x_k, y_k, x_parent = -1, y_parent = -1;
        TreeNode* parent = new TreeNode(-1);
        TreeNode* pre;
        stack<TreeNode*> stk;
        while ((root || !stk.empty()) && (x_parent == -1 || y_parent == -1)) {
            if (root) {
                stk.push(root);
                root = root->left;
                k++;
            } else {
                root = stk.top();
                k--;
                if (!root->right || pre == root->right) {
                    stk.pop();
                    pre = root;
                    if (!stk.empty()) parent = stk.top(); // assured to be right cuz of post-order 
                    if (root->val == x) {
                        x_parent = parent->val;
                        x_k = k;
                    }
                    if (root->val == y) {
                        y_parent = parent->val;
                        y_k = k;
                    }
                    root = nullptr;
                }　else {
                    root = root->right;
                    k++;
                }
            }
        }
        //std::cout << x_k << "\n" << y_k;
        if (x_k == y_k && x_parent != y_parent) return true;
        return false;
    }
};
