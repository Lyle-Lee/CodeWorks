struct Trie {
    Trie* left = nullptr; // current bit = 0
    Trie* right = nullptr; // current bit = 1
    Trie() {}
};

class Solution {
private:
    Trie* root = new Trie();
    int numBit = 30; // the highest bit

public:
    void add(int num) { // regard num as a binary string
        Trie* cur = root;
        for (int k = numBit; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) cur->left = new Trie();
                cur = cur->left;
            } else {
                if (!cur->right) cur->right = new Trie();
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        // to check max possible answer bitwise (find nums[i] given current nums[j])
        Trie* cur = root;
        int x = 0; // result of xor
        for (int k = numBit; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) { // current bit (of nums[i]) should be 1 if possible
                if (cur->right) {
                    cur = cur->right;
                    x = (x << 1) + 1;
                } else {
                    cur = cur->left;
                    x = x << 1;
                }
            } else { // current bit should be 0 if possible
                if (cur->left) {
                    cur = cur->left;
                    x = (x << 1) + 1;
                } else {
                    cur = cur->right;
                    x = x << 1;
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            add(nums[i - 1]); // all nums[0: i - 1] is in Trie
            x = max(x, check(nums[i]));
        }
        return x;
    }
};
