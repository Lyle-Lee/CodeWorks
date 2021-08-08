class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.length(), idx = 0;
        for (string& w: words) {
            for (char& ch: w) {
                if (idx < n && s[idx] == ch) {
                    ++idx;
                } else {
                    return false;
                }
            }
            if (idx == n) return true;
        }
        return false;
    }
};
