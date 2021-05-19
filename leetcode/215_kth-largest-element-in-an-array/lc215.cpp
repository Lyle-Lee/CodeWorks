class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quick selection
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
