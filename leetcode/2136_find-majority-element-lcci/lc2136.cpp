class Solution {
    // Boyer-Moore algorithm
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt == 0) {
                target = nums[i];
                ++cnt;
            } else {
                cnt += target == nums[i] ? 1 : -1;
            }
        }
        if (cnt == 0) return -1;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) ++cnt;
            if (cnt > n / 2) return target;
        }
        return -1;
    }
};
