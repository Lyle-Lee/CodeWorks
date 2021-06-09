class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int numWorks = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        // dp[j][k] stores num. of plans while considering the 0~i-th work with num. of workers <= j, and minProfit is k
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < numWorks; ++i) {
            int member = group[i], prof = profit[i];
            for (int j = n; j >= member; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    dp[j][k] = (dp[j][k] + dp[j - member][max(0, k - prof)]) % MOD;
                    // k is current minProfit, need at least k - prof to achieve k
                    if (i == numWorks - 1) break;
                }
                if (i == numWorks - 1) break;
            }
        }
        return dp[n][minProfit];
    }
};
