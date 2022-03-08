class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> preCandles(n), rightCandles(n);
        int leftCandle = -1, rightCandle = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') {
                if (leftCandle >= 0) preCandles[i] = preCandles[leftCandle] + i - leftCandle - 1;
                leftCandle = i;
            } else {
                if (leftCandle >= 0) preCandles[i] = preCandles[leftCandle];
            }
            if (s[n - 1 - i] == '|') rightCandle = n - 1 - i;
            rightCandles[n - 1 - i] = rightCandle;
        }
        vector<int> ans;
        for (auto& q: queries) {
            ans.push_back(preCandles[q[1]] - (rightCandles[q[0]] < n && rightCandles[q[0]] <= q[1] ? preCandles[rightCandles[q[0]]] : preCandles[q[0]]));
        }
        return ans;
    }
};
