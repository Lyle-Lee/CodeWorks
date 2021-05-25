class Solution {
private:
    const int maxXor = 1 << 10;
    const int INF = 0x3f3f3f3f;

public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        // meaning of dp: min change times when cur group xor = index
        vector<vector<int>> dp(2, vector<int>(maxXor, INF));
        // current dp[0][0] means dp[-1][0] = 0, no element is considered, and otherwise invalid
        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) { // the i-th group in k groups
            unordered_map<int, int> cnt; // apear times of an element in current group
            int size = 0; // total group size
            for (int j = i; j < n; j += k) {
                ++cnt[nums[j]];
                ++size;
            }
            // dp[i][x] = min_x{dp[i - 1][x xor cur] + size - cnt[cur]}
            //          = size + min(min_x{dp[i - 1][x xor cur]}, min_x{dp[i - 1][x xor cur] - cnt[cur]})
            //          = size + min(min_j{dp[i - 1][j]}, min_x{dp[i - 1][x xor cur] - cnt[cur]})
            //          = size + min(t1Min, t2Min)
            int t1Min = *min_element(dp[i & 1].begin(), dp[i & 1].end());
            fill(dp[1 - (i & 1)].begin(), dp[1 - (i & 1)].end(), t1Min);
            for (int x = 0; x < maxXor; ++x) {
                for (auto [cur, countCur]: cnt) {
                    // calculate t2Min
                    dp[1 - (i & 1)][x] = min(dp[1 - (i & 1)][x], dp[i & 1][x ^ cur] - countCur);
                }
            }
            // plus size
            for_each(dp[1 - (i & 1)].begin(), dp[1 - (i & 1)].end(), [&](int& val) {val += size;});
        }
        return dp[k & 1][0];
    }
};
