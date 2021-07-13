class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int colorTheGrid(int m, int n) {
        // m << n, regard m as num of column and pre-process valid case for a row
        unordered_map<int, vector<int>> valid; // <mask, trinary of the mask>
        int maxMask = pow(3, m);
        for (int mask = 0; mask < maxMask; ++mask) {
            vector<int> color;
            int cur = mask;
            int curColor = mask % 3;
            for (int i = 0; i < m; ++i) {
                if (i > 0 && color.back() == curColor) break;
                color.push_back(curColor);
                cur /= 3;
                curColor = cur % 3;
            }
            if (color.size() == m) valid[mask] = move(color);
        }
        // if (n == 1) return valid.size();
        unordered_map<int, vector<int>> adjacent; // <mask, valid adjacent mask>
        for (auto& [mask1, target]: valid) {
            for (auto& [mask2, neighbour]: valid) {
                int idx = 0;
                while (idx < m) {
                    if (target[idx] == neighbour[idx]) break;
                    ++idx;
                }
                if (idx == m) adjacent[mask1].push_back(mask2);
            }
        }
        vector<vector<int>> dp(2, vector<int>(maxMask, 0));
        // dp[i][mask]: num of ways while current paint mask of the i-th row is mask
        for (auto& [mask, _]: valid) dp[0][mask] = 1;
        for (int i = 1; i < n; ++i) {
            for (auto& [mask, _]: valid) {
                for (auto& last: adjacent[mask]) {
                    dp[i % 2][mask] = (dp[i % 2][mask] + dp[(i + 1) % 2][last]) % MOD;
                }
            }
            fill(dp[(i + 1) % 2].begin(), dp[(i + 1) % 2].end(), 0);
        }
        int ans = 0, resIdx = (n - 1) % 2;
        for (auto& [mask, _]: valid) {
            ans = (ans + dp[resIdx][mask]) % MOD;
        }
        return ans;
    }
};
