class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (s1 == s2) return true;
        bool dp[n][n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][0] = s1[i] == s2[j];
                for (int len = 1; len < n; ++len) {
                    dp[i][j][len] = false;
                }
            }
        }
        for (int len = 1; len < n; ++len) { // len + 1 = length
            for (int i = 0; i < n - len; ++i) {
                for (int j = 0; j < n - len; ++j) {
                    for (int k = 0; k < len; ++k) { // k + 1 = substring.length
                        bool a = dp[i][j][k] && dp[i + k + 1][j + k + 1][len - k - 1]; // case1: not scrambled
                        bool b = dp[i][j + len - k][k] && dp[i + k + 1][j][len - k - 1]; // case2: scrambled
                        if (a || b) dp[i][j][len] = true;
                    }
                }
            }
        }
        return dp[0][0][n - 1];
    }
};
