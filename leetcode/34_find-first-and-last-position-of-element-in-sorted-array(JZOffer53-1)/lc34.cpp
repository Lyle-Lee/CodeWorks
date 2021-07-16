class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int lb = binarySearch(nums, target, true);
        int ub = binarySearch(nums, target, false);
        if (lb >= ub) return {-1, -1};
        return {lb, ub - 1};
    }

    int binarySearch(vector<int>& nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1;
        int ans = r + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
