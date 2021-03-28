class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int max_k = INT_MIN; // too large max_k results in 'always false'
        stack<int> stk;
        stk.push(nums[n-1]);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < max_k) return true;
            while (!stk.empty() && stk.top() < nums[i]) {
                max_k = stk.top();
                stk.pop();
            }
            if (nums[i] > max_k) {
                stk.push(nums[i]);
            }
        }
        return false;
    }
};
