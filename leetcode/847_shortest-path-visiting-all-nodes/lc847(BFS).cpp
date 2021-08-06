class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<tuple<int, int, int>> q; // <node, mask, dist>
        int n = graph.size();
        int maxMask = 1 << n;
        vector<vector<int>> visited(n, vector<int>(maxMask, 0)); // to log visited status
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            visited[i][1 << i] = 1;
        }
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == maxMask - 1) return dist;
            for (int v: graph[u]) {
                int mask_v = mask | (1 << v);
                if (!visited[v][mask_v]) {
                    q.emplace(v, mask_v, dist + 1);
                    visited[v][mask_v] = 1;
                }
            }
        }
        return -1; // never
    }
};
