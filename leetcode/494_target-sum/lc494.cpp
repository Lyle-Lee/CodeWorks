class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        // (sum - neg) - neg = target -> sum - target = 2 * neg >= 0
        // neg: sum of elements that should be set to -
        if (sum - target < 0 || (sum - target) % 2 != 0) return 0;
        int n = nums.size(), neg = (sum - target) / 2;
        vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = neg; j >= 0; --j) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
                if (i == n - 1) break;
            }
        }
        return dp[neg];
    }
};
