class Solution {
private:
    unordered_map<int, vector<int>> stations;
    // const static int N = 1e6 + 10;
    // int p[N];

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        // for (int i = 0; i < N; ++i) p[i] = i;
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            for (int s: routes[i]) {
                stations[s].push_back(i);
                // unionFind(s, routes[i][0]);
            }
        }
        // if (!query(source, target)) return -1;
        queue<int> q1, q2;
        unordered_map<int, int> map1, map2;
        q1.push(source);
        q2.push(target);
        map1[source] = 0;
        map2[target] = 0;
        while (!q1.empty() && !q2.empty()) {
            int res = -1;
            if (q1.size() <= q2.size()) res = update(routes, q1, map1, map2);
            else res = update(routes, q2, map2, map1);
            if (res != -1) return res;
        }
        return -1;
    }

    // int find(int x) {
    //     if (p[x] != x) p[x] = find(p[x]);
    //     return p[x];
    // }

    // void unionFind(int a, int b) {
    //     p[find(a)] = p[find(b)];
    // }

    // bool query(int a, int b) {
    //     return find(a) == find(b);
    // }

    int update(vector<vector<int>>& routes, queue<int>& cur, unordered_map<int, int>& curMap, unordered_map<int, int>& other) {
        int station = cur.front();
        cur.pop();
        int step = curMap[station];
        vector<int> nextStatus;
        for (int bus: stations[station]) {
            for (int nextStat: routes[bus]) {
                if (nextStat != station && !curMap.count(nextStat)) nextStatus.push_back(nextStat);
            }
        }
        for (int next: nextStatus) {
            // if (curMap.count(next)) continue;
            if (other.count(next)) return step + 1 + other[next];
            cur.push(next);
            curMap[next] = step + 1;
        }
        return -1;
    }
};
