class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> pre_num(n, 0);
        for (int i = 1; i < n; ++i) {
            int len = 1, pre = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > len) { // found new answer
                        len = dp[j] + 1; // update max_len
                        pre = j; // update pre_num
                    }
                }
            }
            dp[i] = len;
            pre_num[i] = pre;
        }
        // the last id of largest num of answer
        int pre_id = max_element(dp.begin(), dp.end()) - dp.begin();
        int max_len = dp[pre_id];
        vector<int> answer;
        while (max_len > 0) {
            answer.push_back(nums[pre_id]);
            pre_id = pre_num[pre_id]; // back search to append remaining members
            max_len--;
        }
        return answer;
    }
};
