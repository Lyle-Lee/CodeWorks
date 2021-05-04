class Solution {
private:
    const int INF = 0x3f3f3f3f; // no overflow during adding
    using TIII = tuple<int, int, int>;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INF)));
        vector<vector<TIII>> best(m, vector<TIII>(target, {INF, -1, INF})); // {1st, 1st_id, 2nd}
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (houses[i] != 0 && j + 1 != houses[i]) continue; // invalid
                for (int k = 0; k < target; ++k) {
                    if (i == 0) {
                        if (k == 0) dp[i][j][k] = 0; // valid start
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k]; // the same block
                        if (k > 0) {
                            TIII tup = best[i - 1][k - 1];
                            // different block
                            dp[i][j][k] = min(dp[i][j][k], (j == get<1>(tup) ? get<2>(tup) : get<0>(tup)));
                        }
                    }
                    // if no color, paint color and add cost
                    if (dp[i][j][k] != INF && houses[i] == 0) {
                        dp[i][j][k] += cost[i][j];
                    }
                    // update best
                    if (dp[i][j][k] < get<0>(best[i][k])) {
                        get<2>(best[i][k]) = get<0>(best[i][k]); // update 2nd
                        get<0>(best[i][k]) = dp[i][j][k]; // update 1st
                        get<1>(best[i][k]) = j; // update 1st_id
                    } else if (dp[i][j][k] < get<2>(best[i][k])) {
                        get<2>(best[i][k]) = dp[i][j][k];
                    }
                }
            }
        }
        // find answer
        int ans = INF;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INF ? -1 : ans;
    }
};
