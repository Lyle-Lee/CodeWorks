class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n > 0) {
            n = n & (n-1); // reverse lowest bit of n
            result++;
        }
        return result;
    }
};
