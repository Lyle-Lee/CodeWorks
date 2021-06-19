class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<vector<int>> dp(27, vector<int>{}); // dp[i]: valid mask set while total length is i
        dp[0].push_back(0);
        for (auto &s: arr) {
            int mask = str2bin(s);
            if (mask == 0) continue;
            int len = s.length();
            for (int i = len; i <= 26; ++i) {
                if (dp[i - len].size()) {
                    for (int m: dp[i - len]) {
                        if ((m & mask) == 0) dp[i].push_back(m | mask);
                    }
                }
            }
        }
        for (int i = 26; i > 0; --i) {
            if (dp[i].size()) return i;
        }
        return 0;
    }

    int str2bin(string s) {
        int mask = 0;
        for (char c: s) {
            if (mask & (1 << c - 'a')) return 0;
            mask |= 1 << c - 'a';
        }
        return mask;
    }
};
