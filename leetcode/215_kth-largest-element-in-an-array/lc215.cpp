class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quick selection
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return partition(nums, k, 0, nums.size() - 1);
    }

    int partition(vector<int>& nums, int k, int l, int r) {
        int i = l; // pivot
        for (int j = l + 1; j <= r; ++j) {
            if (nums[j] >= nums[l]) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[i]); // nums[i] >= nums[l]
        if (i >= k) return partition(nums, k, l, i - 1);
        if (i < k - 1) return partition(nums, k, i + 1, r);
        return nums[i];
    }
};
