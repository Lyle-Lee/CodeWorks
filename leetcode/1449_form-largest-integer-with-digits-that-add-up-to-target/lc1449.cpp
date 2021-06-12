class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target + 1); // dp[i]: current best string with target = i
        for (int i = 0; i < n; ++i) {
            int c = cost[i];
            for (int j = c; j <= target; ++j) {
                if ((dp[j - c].length() > 0 || j == c) && dp[j - c].length() + 1 >= dp[j].length()) {
                    char digit = '0' + i + 1;
                    if (j == c) dp[j] = digit;
                    else dp[j] = digit + dp[j - c];
                }
            }
        }
        if (dp[target].length() == 0) return "0";
        else return dp[target];
    }
};
