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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        stack<TreeNode*> leftStack, rightStack;
        TreeNode* leftNode = root, *rightNode = root;
        while (leftNode) {
            leftStack.push(leftNode);
            leftNode = leftNode->left;
        }
        while (rightNode) {
            rightStack.push(rightNode);
            rightNode = rightNode->right;
        }
        leftNode = GetLeft(leftStack);
        rightNode = GetRight(rightStack);
        while (leftNode != rightNode) {
            if (leftNode->val + rightNode->val == k) return true;
            if (leftNode->val + rightNode->val > k) {
                rightNode = GetRight(rightStack);
            } else {
                leftNode = GetLeft(leftStack);
            }
        }
        return false;
    }

    TreeNode* GetLeft(stack<TreeNode*>& stk) {
        TreeNode* cur = stk.top();
        stk.pop();
        TreeNode* node = cur->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }
        return cur;
    }

    TreeNode* GetRight(stack<TreeNode*>& stk) {
        TreeNode* cur = stk.top();
        stk.pop();
        TreeNode* node = cur->left;
        while (node) {
            stk.push(node);
            node = node->right;
        }
        return cur;
    }
};
