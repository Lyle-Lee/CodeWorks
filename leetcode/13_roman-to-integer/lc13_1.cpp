class Solution {
private:
    unordered_map<char, int> decode{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int sign = 1;
            if (i < n - 1 && decode[s[i]] < decode[s[i + 1]]) sign = -1;
            ans += sign * decode[s[i]];
        }
        return ans;
    }
};
