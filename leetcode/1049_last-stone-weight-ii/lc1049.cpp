class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for (int w: stones) {
            sum += w;
        }
        int maxNeg = sum / 2; // ans = (sum - neg) - neg = sum - 2 * neg >= 0
        vector<int> dp(maxNeg + 1, 0);
        dp[0] = 1;
        int ans;
        for (int i = 0; i < n; ++i) {
            for (int neg = maxNeg; neg >= 0; --neg) {
                if (neg >= stones[i]) {
                    // to check whether current neg could be constructed
                    dp[neg] = dp[neg] || dp[neg - stones[i]];
                } // else keep
                if (i == n - 1 && dp[neg]) {
                    ans = neg;
                    break;
                }
            }
        }
        return sum - 2 * ans;
    }
};
