class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> minIdx(n, vector<int>(2)), maxIdx(n, vector<int>(2));
        function<void(bool, vector<vector<int>>&)> getRange = [&](bool isMax, vector<vector<int>>& range) {
            stack<int> stk;
            for (int i = 0; i < n; ++i) {
                // the same max/min should be considered only once in a subArray
                // if i < j and nums[i] == nums[j], only nums[i] is considered to be the min, and only nums[j] is considered to be the max
                while (!stk.empty() && (isMax && nums[stk.top()] <= nums[i] || !isMax && nums[stk.top()] > nums[i])) {
                    stk.pop();
                }
                range[i][0] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = n - 1; i >= 0; --i) {
                while (!stk.empty() && (isMax && nums[stk.top()] < nums[i] || !isMax && nums[stk.top()] >= nums[i])) {
                    stk.pop();
                }
                range[i][1] = stk.empty() ? n : stk.top();
                stk.push(i);
            }
        };
        getRange(false, minIdx);
        getRange(true, maxIdx);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)(i - maxIdx[i][0]) * (maxIdx[i][1] - i) * nums[i] - (long long)(i - minIdx[i][0]) * (minIdx[i][1] - i) * nums[i];
        }
        return ans;
    }
};
