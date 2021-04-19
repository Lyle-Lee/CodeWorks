class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (j >= i) {
            if (nums[i] != val) {
                i++;
            }
            if (nums[j] == val) {
                j--;
            } else if (j > i && nums[i] == val) {
                nums[i] = nums[j];
                i++;
                j--;
            }
        }
        return i;
    }
};
