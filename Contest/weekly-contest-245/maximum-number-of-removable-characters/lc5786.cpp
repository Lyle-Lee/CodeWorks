class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size() - 1;
        while (l <= r) {
            int k = (l + r) / 2;
            if (isSubstring(s, p, removable, k)) l = k + 1;
            else r = k - 1;
        }
        return l;
    }
    
    bool isSubstring(string s, string p, vector<int>& removable, int k) {
        int m = s.length(), n = p.length();
        vector<int> removed(m, 0);
        for (int idx = 0; idx <= k; ++idx) {
            removed[removable[idx]] = 1;
        }
        int i = 0, j = 0;
        while (i < m && j < n) {
            while (i < m && removed[i]) ++i;
            if (i == m) return false;
            if (s[i] == p[j]) ++j;
            ++i;
        }
        if (j == n) return true;
        return false;
    }
};
