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
private:
    stack<TreeNode*> stk1, stk2;

public:
    TreeNode* nextLeaf(TreeNode* root, stack<TreeNode*>& stk) {
        TreeNode* leaf = new TreeNode(-1);
        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (root->right == nullptr && root->left == nullptr) return root; // valid leaf
                root = root->right;
            }
        }
        return leaf;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int a = -2, b = -2;
        while (a != -1 && b != -1) {
            if (a == -2) a = nextLeaf(root1, stk1)->val;
            else a = nextLeaf(nullptr, stk1)->val;
            if (b == -2) b = nextLeaf(root2, stk2)->val;
            else b = nextLeaf(nullptr, stk2)->val;
            if (a != b) return false;
        }
        return true;
    }
};
