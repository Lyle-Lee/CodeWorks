class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        int n = security.size();
        if (n < 2 * time + 1) return ans;
        vector<int> before(n), after(n);
        for (int i = 1; i < n; ++i) {
            if (security[i - 1] >= security[i]) before[i] = before[i - 1] + 1;
            if (security[n - 1 - i] <= security[n - i]) after[n - 1 - i] = after[n - i] + 1;
        }
        for (int i = time; i < n - time; ++i) {
            if (before[i] >= time && after[i] >= time) ans.push_back(i);
        }
        return ans;
    }
};
