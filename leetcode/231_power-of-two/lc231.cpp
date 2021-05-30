class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n & (n - 1): set the last 1 to 0
        return n > 0 && (n & (n - 1)) == 0;
        // n & -n: get lowest 1 (contains rest 0s)
        // return n > 0 && (n & -n) == n;
    }
};
