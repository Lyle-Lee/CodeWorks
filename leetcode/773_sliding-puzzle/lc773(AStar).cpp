struct Node {
    // Manhattan distance for every block
    static constexpr array<array<int, 6>, 6> dist = {{
        {0, 1, 2, 1, 2, 3},
        {1, 0, 1, 2, 1, 2},
        {2, 1, 0, 3, 2, 1},
        {1, 2, 3, 0, 1, 2},
        {2, 1, 2, 1, 0, 1},
        {3, 2, 1, 2, 1, 0}
    }};
    string status;
    int val;

    static int getH(const string& status) {
        int h = 0;
        for (int i = 0; i < 6; ++i) {
            if (status[i] != '0') h += dist[i][status[i] - '1'];
        }
        return h;
    }

    bool operator< (const Node& other) const {
        return val > other.val;
    }

    Node(const string& s, int g): status(s), val(g + getH(s)) {}
};

class Solution {
private:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        priority_queue<Node> q;
        unordered_map<string, int> map;
        string start;
        for (auto &v: board) {
            for (int num: v) {
                start += '0' + num;
            }
        }
        string end = "123450";
        if (start == end) return 0;
        if (!check(start)) return -1;
        q.emplace(start, 0);
        map[start] = 0;
        while (!q.empty()) {
            Node cur = q.top();
            int step = map[cur.status];
            q.pop();
            vector<string>&& nextStatus = search(cur.status); // r-value reference
            for (auto &next: nextStatus) {
                if (!map.count(next) || map[next] > step + 1) {
                    if (next == end) return step + 1;
                    q.emplace(next, step + 1);
                    map[next] = step + 1;
                }
            }
        }
        return -1;
    }

    vector<string> search(string& status) {
        vector<string> ret;
        int i = 0;
        while (status[i] != '0') ++i;
        for (auto pos: neighbors[i]) {
            swap(status[i], status[pos]);
            ret.push_back(status);
            swap(status[i], status[pos]);
        }
        return ret;
    }

    bool check(string& s) {
        int cnt = 0;
        for (int i = 0; i < 6; ++i) {
            if (s[i] == '0') continue;
            for (int j = i + 1; j < 6; ++j) {
                if (s[j] == '0') continue;
                if (s[i] < s[j]) ++cnt;
            }
        }
        return cnt % 2 == 0;
    }
};
