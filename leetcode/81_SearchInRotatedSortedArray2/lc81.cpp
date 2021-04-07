class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        while (k < n - 1 && nums[k] <= nums[k+1]) {
            k++;
        }
        int left = 0;
        int right = n - 1;
        while (right - left >= 0) {
            int mid = (left + right) / 2; // pseudo index
            int mid_id; // true index
            if (mid >= n - k - 1) mid_id = mid - (n - k - 1); // mid in left part (was not moved)
            else mid_id = mid + k + 1; // mid in the right part (was moved)
            if (nums[mid_id] == target) return true;
            else if (nums[mid_id] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
