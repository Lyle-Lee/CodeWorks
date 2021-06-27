class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int goal = n * n;
        queue<int> q;
        unordered_map<int, int> map;
        q.push(1);
        map[1] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int step = map[cur];
            for (int i = 1; i <= 6; ++i) {
                int next = cur + i;
                if (next > goal) break;
                auto pos = calcPos(next, n);
                int jump = board[pos.first][pos.second];
                if (jump != -1) next = jump;
                if (map.count(next)) continue;
                if (next == goal) return step + 1;
                q.push(next);
                map[next] = step + 1;
            }
        }
        return -1;
    }

    pair<int, int> calcPos(int idx, int n) {
        int row, col;
        int div = idx / n;
        if (idx % n == 0) {
            row = n - div;
            col = div % 2 == 0 ? 0 : n - 1;
        } else {
            row = n - div - 1;
            col = div % 2 == 0 ? idx % n - 1 : n - idx % n;
        }
        return {row, col};
    }
};
