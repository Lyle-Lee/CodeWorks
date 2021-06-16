class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // return true;
        int n = piles.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = piles[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] > 0;
    }
};
