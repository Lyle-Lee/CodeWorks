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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int answer = 0;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root == nullptr) {
                root = stk.top();
                stk.pop();
                if (root->val < high) low = root->val;
                else if (root->val == high) {
                    answer += high;
                    break;
                }
            }
            if (root->val > low) {
                stk.push(root);
                root = root->left;
            } else {
                if (root->val == low) answer += root->val;
                root = root->right;
            }
        }
        return answer;
    }
};
