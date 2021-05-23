struct Trie {
    Trie* left = nullptr; // current bit is 0
    Trie* right = nullptr; // current bit is 1
    Trie() {}
};

class Solution {
private:
    Trie* root = new Trie();
    int numBit = 30; // the highest bit

public:
    void add(int num) {
        Trie* cur = root;
        for (int i = numBit; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (!cur->left) cur->left = new Trie();
                cur = cur->left;
            } else {
                if (!cur->right) cur->right = new Trie();
                cur = cur->right;
            }
        }
    }

    int getMaxXor(int x) {
        Trie* cur = root;
        int res = 0;
        for (int i = numBit; i >= 0; --i) {
            int xBit = (x >> i) & 1;
            if (xBit == 0) {
                if (cur->right) {
                    res |= 1 << i; // current bit could be 1
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->left) {
                    res |= 1 << i; // current bit could be 1
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int qSize = queries.size();
        for (int i = 0; i < qSize; ++i) {
            queries[i].push_back(i); // index of query
        }
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {return a[1] < b[1];});
        vector<int> ans(qSize);
        int idx = 0, n = nums.size();
        for (auto &query : queries) {
            while (nums[idx] <= query[1] && idx < n) {
                add(nums[idx]);
                ++idx;
            }
            if (idx == 0) ans[query[2]] = -1; // all element > m
            else {
                if (query[1] == 0) ans[query[2]] = query[0];
                else ans[query[2]] = getMaxXor(query[0]);
            }
        }
        return ans;
    }
};
