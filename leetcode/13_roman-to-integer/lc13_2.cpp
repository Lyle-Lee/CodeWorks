const pair<string, int> decode[] = {
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1}
};

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        for (const auto &[str, val]: decode) {
            int size = str.length();
            while(i + size <= n && s.substr(i, size) == str) {
                ans += val;
                i += size;
            }
            if (i >= n) break;
        }
        return ans;
    }
};
