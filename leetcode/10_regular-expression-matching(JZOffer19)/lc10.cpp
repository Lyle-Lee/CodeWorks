class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 0) {
                    if (p[j - 1] == '*') dp[i][j] = dp[i][j - 2];
                } else {
                    if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else if (p[j - 1] == '*') {
                        if (p[j - 2] == '.' || s[i - 1] == p[j - 2]) {
                            dp[i][j] = dp[i - 1][j] | dp[i][j - 2];
                        } else dp[i][j] = dp[i][j - 2]; // no generation
                    }
                }
            }
        }
        return dp[m][n] == 1;
    }
};
