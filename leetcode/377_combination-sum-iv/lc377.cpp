class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //int min = *min_element(nums.begin(), nums.end());
        //int m = target - min + 1;
        //if (m <= 0) return 0;
        int n = nums.size();
        //vector<vector<int>> dp(m, vector<int>(n, 0)); // current target = min + index
        //for (int i = 0; i < m; ++i) {
        //    for (int j = 0; j < n; ++j) { // nums[j]: 1st element of current combination 
        //        if (nums[j] == min + i) dp[i][j] = 1;
        //        else if (i - nums[j] >= 0) { // min + i - nums[j] >= min
        //            int new_target = i - nums[j]; // index of new target
        //            dp[i][j] = accumulate(dp[new_target].begin(), dp[new_target].end(), (long long)0);
                    // use long long because num of sub-status may overflow
        //        }
        //    }
        //}
        //return accumulate(dp[m - 1].begin(), dp[m - 1].end(), 0);
        vector<int> dp(target + 1, 0); // 2d -> 1d version
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (int num: nums) {
                if (num <= i) dp[i] += (long long)dp[i - num];
                else break; // stop search if nums is sorted
            }
        }
        return dp[target];
    }
};
