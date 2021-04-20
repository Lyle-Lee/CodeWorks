// The KMP algorithm.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) return 0;
        vector<int> skip(m, 0); // same prefix and suffix length; skip to which id when wrong mapping
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) j = skip[j - 1]; // could not keep current pre-suf pair
            if (needle[i] == needle[j]) j++; // prefix == suffix
            skip[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (m - j > n - i) break;
            while (j > 0 && haystack[i] != needle[j]) j = skip[j - 1]; // fix i, move j
            if (haystack[i] == needle[j]) j++;
            if (j == m) return i - m + 1;
        }
        return -1;
    }
};
