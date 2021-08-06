class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[nums[i]] != nums[i]) {
                swap(nums[nums[i]], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) return nums[i];
        }
        return -1; // never
    }
};
