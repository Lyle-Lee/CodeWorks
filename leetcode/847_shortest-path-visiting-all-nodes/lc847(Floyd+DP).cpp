class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int inf = INT_MAX / 2;
        int n = graph.size();
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
            for (int j: graph[i]) {
                dist[i][j] = 1;
            }
        }
        for (int k = 0; k < n; ++k) { // Floyd
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int maxMask = 1 << n; // use 0b mask to memorize all visited node as status
        vector<vector<int>> dp(n, vector<int>(maxMask, inf));
        for (int mask = 1; mask < maxMask; ++mask) {
            if ((mask & (mask - 1)) == 0) { // start node
                int u = __builtin_ctz(mask);
                dp[u][mask] = 0;
            } else {
                for (int u = 0; u < n; ++u) {
                    if (mask & (1 << u)) { // possible end node
                        for (int v = 0; v < n; ++v) {
                            if ((mask & (1 << v)) && v != u) { // last visited node
                                dp[u][mask] = min(dp[u][mask], dp[v][mask ^ (1 << u)] + dist[v][u]);
                            }
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < n; ++i) ans = min(ans, dp[i][maxMask - 1]);
        return ans;
    }
};
