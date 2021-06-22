class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        sort(s.begin(), s.end());
        do {
            ans.push_back(s);
        } while (nextPermutation(s));
        return ans;
    }

    bool nextPermutation(string& s) { // process by refrence
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) { // the rightmost i that statisfies s[i] < s[i + 1]
            --i;
        }
        if (i < 0) return false;
        int j = s.size() - 1;
        while (j > i && s[j] <= s[i]) { // the smallest s[j] that larger than s[i] in right of i
            --j;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }
};
