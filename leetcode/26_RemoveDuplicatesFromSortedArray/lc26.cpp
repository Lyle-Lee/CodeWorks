class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num: nums) { // double ptr
            if (i < 1 || nums[i - 1] < num) {
                if (nums[i] < num) nums[i] = num;
                i++;
            }
        }
        return i;
    }
};
