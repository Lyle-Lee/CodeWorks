class Solution {
// private:
    // unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
public:
    int countPrimeSetBits(int left, int right) {
        const int primes = 0b10100010100010101100;
        function<bool(int)> check = [&](int x) {
            x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
            x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
            x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
            return primes & (1 << x);
        };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (check(i)) ++ans;
        }
        return ans;
    }
};
