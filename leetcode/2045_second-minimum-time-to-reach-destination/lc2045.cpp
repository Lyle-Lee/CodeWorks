class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> pathLen(n + 1, vector<int>(2, -1));
        pathLen[1][0] = 0;
        queue<int> q;
        int depth = 1;
        q.push(1);
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt > 0) {
                int cur = q.front();
                q.pop();
                for (int next: g[cur]) {
                    if (pathLen[next][0] == -1) {
                        q.push(next);
                        pathLen[next][0] = depth;
                    } else if (pathLen[next][1] == -1 && depth > pathLen[next][0]) {
                        q.push(next);
                        pathLen[next][1] = depth;
                        if (next == n) break;
                    }
                }
                if (pathLen[n][1] != -1) break;
                --cnt;
            }
            if (pathLen[n][1] != -1) break;
            ++depth;
        }
        int ans = 0, T = 2 * change;
        for (int i = 0; i < pathLen[n][1]; ++i) {
            if (ans % T < change) ans += time;
            else ans += time + T - (ans % T);
        }
        return ans;
    }
};
