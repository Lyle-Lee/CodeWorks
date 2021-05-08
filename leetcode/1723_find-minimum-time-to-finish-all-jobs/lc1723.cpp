class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n, 0); // sum of all possible combinations of jobs
        for (int i = 1; i < (1 << n); ++i) {
            // ctz: count trailing zeros (count num of 0s from last 0 to 1st 1 bit)
            // x: index of jobs, every bit is count as a job (1 means done otherwise 0)
            int x = __builtin_ctz(i);
            int y = i - (1 << x); // status already counted
            sum[i] = sum[y] + jobs[x];
        }
        // best answer of assigning current job set (mark as j) to k workers
        vector<vector<int>> dp(k, vector<int>(1 << n, 0));
        for (int i = 0; i < (1 << n); ++i) {
            dp[0][i] = sum[i]; // cases of only 1 worker
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 1; j < (1 << n); ++j) {
                int min_t = INT_MAX; // min time of current combination
                for (int x = j; x > 0; x = (x - 1) & j) { // count subsets
                    min_t = min(min_t, max(dp[i - 1][j - x], sum[x])); // assign subset x to i-th worker
                }
                dp[i][j] = min_t;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};
