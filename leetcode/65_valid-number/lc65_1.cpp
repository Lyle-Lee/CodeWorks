class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (idx != -1) return false;
                idx = i;
            }
        }
        bool ans;
        if (idx != -1) {
            ans = check(s, 0, idx - 1, false) && check(s, idx + 1, n - 1, true);
        } else {
            ans = check(s, 0, n - 1, false);
        }
        return ans;
    }

    bool check(string s, int start, int end, bool mustInt) {
        if (start > end) return false;
        if (s[start] == '+' || s[start] == '-') ++start;
        bool hasDot = false, hasNum = false;
        for (int i = start; i <= end; ++i) {
            if (s[i] == '.') {
                if (mustInt || hasDot) return false;
                hasDot = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                hasNum = true;
            } else {
                return false;
            }
        }
        return hasNum;
    }
};
