class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> first, last; // <ch, idx>
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (first.count(s[i])) last[s[i]] = i;
            else first[s[i]] = i;
        }
        int ans = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (!first.count(ch) || !last.count(ch)) continue;
            int state = 0;
            for (int i = first[ch] + 1; i < last[ch]; ++i) {
                state |= 1 << s[i] - 'a';
            }
            while (state > 0) {
                ++ans;
                state &= state - 1;
            }
        }
        return ans;
    }
};
