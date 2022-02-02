class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size(), l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (n - i <= r - l) break;
            int lower = 0, upper = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] < 'a') upper |= 1 << (s[j] - 'A');
                else lower |= 1 << (s[j] - 'a');
                if (upper == lower && j - i + 1 > r - l) {
                    r = j + 1;
                    l = i;
                }
            }
        }
        return s.substr(l, r - l);
    }
};
