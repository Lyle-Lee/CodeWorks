class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        //int n = nums.size();
        //int ans = nums[0];
        //for (int i = 1; i < n; ++i) {
        //    if (nums[i - 1] < nums[i]) {
        //        if (i == 1) return ans;
        //        if (i == n - 1 || nums[i] < nums[i + 1]) {
        //            ans = nums[i];
        //            break;
        //        }
        //    }
        //}
        //return ans;
        int a = 0, b = 0;
        for (int num: nums) { // digital circuits
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};
