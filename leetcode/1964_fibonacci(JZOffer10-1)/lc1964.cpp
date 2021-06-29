class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        while (n - 1 > 0) {
            int tmp = b;
            b = (a + b) % MOD;
            a = tmp;
            --n;
        }
        return b;
    }
};
