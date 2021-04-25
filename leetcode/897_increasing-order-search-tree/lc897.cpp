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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        //while (root->left) {
        //    stk.push(root);
        //    root = root->left;
        //}
        TreeNode* dummy_node = new TreeNode(-1);
        //TreeNode* cur = root;
        TreeNode* cur = dummy_node;
        TreeNode* next;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            next = stk.top();
            stk.pop();
            cur->right = next;
            if (next->left) next->left = nullptr; // reverse arrow
            if (next->right) root = next->right;
            //if (cur->right) {
            //    next = cur->right;
            //    if (next->left) {
            //        while (next->left) {
            //            stk.push(next);
            //            next = next->left;
            //        }
            //        cur->right = next;
            //    } // else already satisfied
            //} else {
            //    next = stk.top();
            //    cur->right = next;
            //    stk.pop();
            //}
            //if (next->left) next->left = nullptr;
            cur = next;
        }
        return dummy_node->right;
    }
};
