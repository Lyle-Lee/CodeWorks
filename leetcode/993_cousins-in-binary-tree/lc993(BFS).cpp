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
        if (root->val == x || root->val == y) return false;
        int k = 0;
        int x_parent = 0, y_parent = 0;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        TreeNode* cur;
        while (!q.empty()) {
            int i = q.size();
            while (i > 0) { // search by the same depth
                cur = q.front();
                q.pop();
                ++flag; // different parent
                if (cur->left) {
                    q.push(cur->left);
                    if (cur->left->val == x) x_parent = flag;
                    if (cur->left->val == y) y_parent = flag;
                }
                if (cur->right) {
                    q.push(cur->right);
                    if (cur->right->val == x) x_parent = flag;
                    if (cur->right->val == y) y_parent = flag;
                }
                --i;
            }
            if (x_parent && y_parent) return x_parent != y_parent;
            if (x_parent || y_parent) return false;
        }
        return false; // only possible while no x neither y is mapped
    }
};
