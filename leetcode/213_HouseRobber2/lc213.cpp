class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int cur = nums[1], pre = nums[0];
        if (n == 2) return max(cur, pre);
        for (int i = 1; i < n - 1; ++i) { // consider the 1st house (no last house)
            if (i < 2) cur = max(cur, pre);
            else { // new cur = dp[n], cur = dp[n-1], pre = dp[n-2]
                int new_cur;
                new_cur = max(cur, pre + nums[i]);
                pre = cur;
                cur = new_cur;
            }
        }
        int cur2 = nums[2];
        pre = nums[1];
        for (int i = 2; i < n; ++i) { // consider the last house (no 1st house)
            if (i < 3) cur2 = max(cur2, pre);
            else { // new cur = dp[n], cur = dp[n-1], pre = dp[n-2]
                int new_cur;
                new_cur = max(cur2, pre + nums[i]);
                pre = cur2;
                cur2 = new_cur;
            }
        }
        return max(cur, cur2);
    }
};
