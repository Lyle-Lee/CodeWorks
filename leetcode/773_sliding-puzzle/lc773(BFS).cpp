class Solution {
private:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> q;
        unordered_map<string, int> map;
        string start;
        for (auto &v: board) {
            for (auto num: v) {
                start += '0' + num;
            }
        }
        string end = "123450";
        if (start == end) return 0;
        q.push(start);
        map[start] = 0;
        while (!q.empty()) {
            string cur = q.front();
            int step = map[cur];
            q.pop();
            vector<string>&& nextStatus = search(cur); // r-value reference
            for (auto &next: nextStatus) {
                if (map.count(next)) continue; // already visited
                if (next == end) return step + 1;
                q.push(next);
                map[next] = step + 1;
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
};
