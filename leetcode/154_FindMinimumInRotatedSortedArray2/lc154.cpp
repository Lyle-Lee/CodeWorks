class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left]; // monotonic array, minimum is left
            int pivot = (left + right) / 2;
            if (nums[right] > nums[pivot]) {
                right = pivot;
                left++; // nums[left] >= nums[right] > nums[pivot], left can be ignored
            }
            //if (nums[left] < nums[pivot]) left = pivot + 1;
            else if (nums[right] < nums[pivot]) left = pivot + 1;
            //else if (nums[left] > nums[pivot]) {
            //    right = pivot;
            //    left++;
            //}
            else right--; // the same element, linear search
            //else left++;
        }
        return nums[left];
    }
};
