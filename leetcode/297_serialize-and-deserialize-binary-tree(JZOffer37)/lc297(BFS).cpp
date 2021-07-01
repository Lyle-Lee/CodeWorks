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
        queue<TreeNode*> q;
        q.push(root);
        string encode;
        while (!q.empty()) {
            if (q.front() == nullptr) {
                q.pop();
                encode += "x,";
            } else {
                TreeNode* cur = q.front();
                q.pop();
                encode += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        // encode += "x";
        // cout << encode << endl;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "x,") return nullptr;
        vector<string> decode;
        string str;
        for (char c: data) {
            if (c == ',') {
                decode.push_back(str);
                str.clear();
            } else {
                str += c;
            }
        }
        // decode.push("x");
        int ptr = 0;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(decode[0]));
        q.push(root);
        for (int i = 0; i < decode.size(); ++i) {
            if (decode[i] == "x") continue;
            TreeNode* cur = q.front();
            q.pop();
            string l = decode[ptr + 1], r = decode[ptr + 2];
            if (l != "x") {
                cur->left = new TreeNode(stoi(l));
                q.push(cur->left);
            }
            if (r != "x") {
                cur->right = new TreeNode(stoi(r));
                q.push(cur->right);
            }
            ptr += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
