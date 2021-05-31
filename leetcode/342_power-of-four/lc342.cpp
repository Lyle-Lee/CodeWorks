class Solution {
public:
    bool isPowerOfFour(int n) {
        // power of 4 must be power of 2, and the only 1 appears at even bit, eg. 16 = 0b10000
        return n > 0 && (n & -n) == n && (n & 0x2aaaaaaa) == 0;
        // if n is power of 4 then n % 3 == 1, otherwise n % 3 == 2 if n is power of 2
        //return n > 0 && (n & -n) == n && n % 3 == 1;
    }
};
