class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // store the best length of subsets
        for (string s: strs) {
            vector<int>&& ZerosOnes = countZerosOnes(s);
            int zeros = ZerosOnes[0], ones = ZerosOnes[1];
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }

    vector<int> countZerosOnes(string str) {
        vector<int> cnt(2);
        for (char c: str) {
            ++cnt[c - '0'];
        }
        return cnt;
    }
};
