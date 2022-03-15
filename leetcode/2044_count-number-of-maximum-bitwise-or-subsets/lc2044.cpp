class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, n = nums.size(), ans = 0;
        function<void(int, int)> dfs = [&](int idx, int cur) {
            if (idx == n - 1) {
                if (cur > maxOR) {
                    maxOR = cur;
                    ans = 1;
                } else if (cur == maxOR) {
                    ++ans;
                }
                return;
            }
            dfs(idx + 1, cur);
            dfs(idx + 1, cur | nums[idx + 1]);
        };
        dfs(-1, 0);
        return ans;
    }
};
