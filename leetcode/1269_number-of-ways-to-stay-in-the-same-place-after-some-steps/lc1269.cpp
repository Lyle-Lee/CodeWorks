class Solution {
public:
    const int MODNUM = 1e9 + 7;

    int numWays(int steps, int arrLen) {
        int max_col = min(arrLen - 1, steps / 2);
        // only need steps i - 1 to calculate steps i
        vector<vector<int>> dp(2, vector<int>(max_col + 1, 0));
        dp[0][0] = 1; // only 1 case of '0 step to arrive index 0'
        for (int i = 1; i <= steps; ++i) {
            int bound = min(i, max_col); // max possible j at steps i
            for (int j = 0; j <= bound; ++j) {
                dp[1][j] = dp[0][j];
                if (j > 0) dp[1][j] = (dp[1][j] + dp[0][j - 1]) % MODNUM;
                if (j < bound) dp[1][j] = (dp[1][j] + dp[0][j + 1]) % MODNUM;
            }
            dp[0] = dp[1]; // update for next 'steps'
        }
        return dp[1][0];
    }
};
