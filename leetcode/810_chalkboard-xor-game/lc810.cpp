class Solution {
    // Game. (sumXOR xor nums[0]) xor ... xor (sumXOR xor nums[n - 1]) = sumXOR xor (n + 1)times
    // if n is even then there must be a case where the result is not 0 after removing a num, Bob must lose
    // if sumXOR == 0 or n is even, Alice wins; otherwise Bob wins
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        if ((n & 1) == 0) return true;
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res == 0;
    }
};
