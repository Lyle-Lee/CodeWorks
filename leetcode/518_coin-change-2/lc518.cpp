class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0); // dp[i]: num of schemes that exactly combine to form i
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int coin = coins[i];
            for (int j = coin; j <= amount; ++j) {
                // before update, dp[j] has not considered the i-th coin
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};
