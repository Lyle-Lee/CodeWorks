class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length();
        if (n == 1) return 1;
        int cur = 1, pre = 1; // cur = dp[i-1]; pre = dp[i-2]
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2') return 0;
                cur = pre; // must be s[:i-2] + s[i-1:i], give up 'cur' branch
            } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] - '6' <= 0) {
                int tmp = cur;
                cur = cur + pre; // s[:i-1] + s[i] or s[:i-2] + s[i-1:i]
                pre = tmp;
            } else {
                pre = cur; // must be s[:i-1] + s[i], give up 'pre' branch
            }
        }
        return cur;
    }
};
