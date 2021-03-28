class Solution {
public:
    int numDistinct(string s, string t) {
        int len_t = t.length();
        int len_s = s.length();
        if (len_t > len_s) return 0;
        //int result = 0;
        //if (len_t == 1) {
        //    for (int i = 0; i < len_s; i++) {
        //        if (s[i] == t[0]) result++;
        //    }
        //    return result;
        //}
        //int start = 0;
        //while (len_s - start >= len_t) {
        //    if (s[start] == t[0]) {
        //        result += numDistinct(s.substr(start+1, len_s-start-1), t.substr(1, len_t-1));
        //    }
        //    start++;
        //}
        //return result;
        vector<vector<long>> dp(len_t + 1, vector<long>(len_s + 1));
        for (int i = 0; i <= len_s; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= len_t; i++) {
            for (int j = 1; j <= len_s; j++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[len_t][len_s];
    }
};
