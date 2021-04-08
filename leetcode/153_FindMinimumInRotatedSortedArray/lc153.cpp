class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] < nums[n-1]) return nums[0];
        int left = 0;
        int right = n - 1;
        while (left < right) { // binary search
            int pivot = (left + right) / 2;
            if (nums[pivot] < nums[right]) right = pivot;
            else left = pivot + 1;
        }
        return nums[left];
    }
};
