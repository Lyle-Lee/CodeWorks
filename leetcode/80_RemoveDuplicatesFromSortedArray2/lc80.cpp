class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num: nums) {
            if (i < 2 || nums[i-2] < num) {
                nums[i] = num; // valid number discovered, put it to pos i
                i++; // length of new array
            }
        }
        return i;
    }
};
