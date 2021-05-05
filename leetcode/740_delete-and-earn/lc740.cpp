class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 0); // use dp[0] as zero start
        int last = 0; // last valid index (of dp) if current element is selected
        int next = 0; // next last
        dp[1] = nums[0];
        int target = nums[0]; // to store sum of the same element
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                target += nums[i];
                dp[i + 1] = max(dp[i], dp[last] + target);
            } else {
                target = nums[i];
                if (nums[i] == nums[i - 1] + 1) {
                    if (next && last != next) last = next;
                    dp[i + 1] = max(dp[i], dp[last] + nums[i]);
                } else {
                    dp[i + 1] = dp[i] + nums[i];
                    last = i;
                }
                next = i;
            }
        }
        return dp[n];
    }
};
