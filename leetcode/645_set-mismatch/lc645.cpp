class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0, s = 0;
        int total = (1 + n) * n / 2;
        for (int num: nums) {
            s += num;
            xorSum ^= num;
        }
        for (int i = 1; i <= n; ++i) {
            xorSum ^= i;
        }
        // all normal nums now have themselves xored, 
        // result should be the repeat num(x) xor missed num(y) -> xorSum = x ^ y
        int lowBit = xorSum & (-xorSum);
        int num1 = 0, num2 = 0;
        for (int num: nums) {
            if ((num & lowBit) == 0) num1 ^= num;
            else num2 ^= num;
        }
        for (int i = 1; i <= n; ++i) {
            if ((i & lowBit) == 0) num1 ^= i;
            else num2 ^= i;
        }
        // num1 = x, num2 = y or num1 = y, num2 = x
        vector<int> ans(2);
        if (num1 + total - s == num2) {
            ans[0] = num1;
            ans[1] = num2;
        } else {
            ans[0] = num2;
            ans[1] = num1;
        }
        return ans;
    }
};
