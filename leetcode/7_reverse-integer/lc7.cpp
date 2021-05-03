class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
            // overflow if ans * 10 + digit > INT_MAX or < INT_MIN, note (x % 10) / 10 = 0
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};
