class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n); // to pair index of '(' and ')'
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }
        string ans;
        int step = 1, idx = 0;
        while (idx < n) {
            if (s[idx] == '(' || s[idx] == ')') {
                idx = pair[idx];
                step = -step;
            } else {
                ans.push_back(s[idx]);
            }
            idx += step;
        }
        return ans;
    }
};
