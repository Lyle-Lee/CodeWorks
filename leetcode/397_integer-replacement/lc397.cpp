class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        int ans = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
                ++ans;
            } else if (n > 3 && n % 4 == 3) {
                n = (n + 1) / 2;
                ans += 2;
            } else {
                n = (n - 1) / 2;
                ans += 2;
            }
        }
        return ans;
    }
};
