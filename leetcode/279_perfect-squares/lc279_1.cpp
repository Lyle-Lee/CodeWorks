class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int num = 1; num * num <= n; ++num) {
            int pow = num * num;
            for (int i = pow; i <= n; ++i) {
                dp[i] = min(dp[i], dp[i - pow] + 1);
            }
        }
        return dp[n];
    }
};
