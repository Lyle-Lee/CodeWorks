class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> g(n);
        vector<int> visited(n);
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int ans = 0, depth = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len > 0) {
                int cur = q.front();
                q.pop();
                for (int next: g[cur]) {
                    if (visited[next]) continue;
                    int arriveTime = depth * 2;
                    int send = (arriveTime - 1) / patience[next] + 1;
                    ans = max(ans, arriveTime + (send - 1) * patience[next]);
                    q.push(next);
                    visited[next] = 1;
                }
                --len;
            }
            ++depth;
        }
        return ans + 1;
    }
};
