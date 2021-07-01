class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        // unordered_map<int, vector<int>> map;
        // for (auto &r: relation) {
        //     map[r[0]].push_back(r[1]);
        // }
        // queue<int> q;
        // q.push(0);
        // int ans = 0;
        // for (int i = 0; i < k; ++i) {
        //     int cnt = q.size();
        //     while (cnt > 0) {
        //         int cur = q.front();
        //         q.pop();
        //         for (int target: map[cur]) {
        //             q.push(target);
        //             if (i == k - 1 && target == n - 1) ++ans;
        //         }
        //         --cnt;
        //     }
        // }
        // return ans;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i <= k; ++i) {
            vector<int> next(n, 0);
            for (auto &r: relation) {
                next[r[1]] += dp[r[0]];
            }
            dp = next;
        }
        return dp[n - 1];
    }
};
