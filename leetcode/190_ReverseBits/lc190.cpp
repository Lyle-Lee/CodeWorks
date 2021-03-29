class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0) return 0;
        uint32_t result = 0;
        if (n % 2 == 1) result = 1;
        n = n >> 1;
        for (int i = 0; i < 31; i++) {
            result = result << 1;
            result += n & 1;
            n = n >> 1;
        }
        return result;
    }
};
