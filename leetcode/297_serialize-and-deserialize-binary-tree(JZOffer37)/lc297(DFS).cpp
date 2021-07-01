/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // if (root == nullptr) return "x";
        stack<TreeNode*> stk;
        string encode;
        while (root != nullptr || !stk.empty()) {
            if (root != nullptr) {
                stk.push(root);
                encode += to_string(root->val) + ",";
                root = root->left;
            } else {
                encode += "x,";
                root = stk.top();
                stk.pop();
                root = root->right;
            }
        }
        encode += "x";
        // cout << encode << endl;
        return encode;
    }

    TreeNode* dfs(queue<string>& q) {
        if (q.front() == "x") {
            q.pop();
            return nullptr;
        }
        TreeNode* cur = new TreeNode(stoi(q.front()));
        q.pop();
        cur->left = dfs(q);
        cur->right = dfs(q);
        return cur;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "x") return nullptr;
        queue<string> decode;
        string str;
        for (char c: data) {
            if (c == ',') {
                decode.push(str);
                str.clear();
            } else {
                str += c;
            }
        }
        decode.push("x");
        return dfs(decode);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
