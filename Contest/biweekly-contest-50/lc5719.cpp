// The 3rd problem of 🐱 50th.

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            res ^= nums[i];
        }
        int max_num = (1 << maximumBit) - 1;
        vector<int> answer;
        answer.push_back(max_num - res);
        for (int i = n - 1; i > 0; --i) {
            res ^= nums[i];
            answer.push_back(max_num - res);
        }
        return answer;
    }
};
