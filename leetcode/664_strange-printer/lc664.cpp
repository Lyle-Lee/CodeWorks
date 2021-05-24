class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        int m = 1;
        // Consecutive identical characters can be compressed into 1, without affecting the final result
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[m - 1]) {
                s[m++] = s[i];
            }
        }
        vector<vector<int>> dp(m ,vector<int>(m));
        // dp[i][j] means min times for printing interval s[i : j]
        for (int i = m - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < m; ++j) {
                if (s[i] == s[j]) dp[i][j] = dp[i][j - 1];
                else {
                    int minAns = INT_MAX;
                    for (int k = i; k < j; ++k) {
                        minAns = min(minAns, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = minAns;
                }
            }
        }
        return dp[0][m - 1];
    }
};
