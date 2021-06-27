class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        while (m >= 2 && n >= 2) {
            int total = 2 * m + 2 * n - 4;
            int move = k % total;
            if (move > 0) {
                queue<int> q;
                for (int i = 0; i < total; ++i) {
                    vector<int>&& pos = calculatePos(i, m, n, cnt);
                    q.push(grid[pos[0]][pos[1]]);
                }
                while (!q.empty()) {
                    int idx = total - q.size() - move;
                    if (idx < 0) idx += total;
                    vector<int>&& pos = calculatePos(idx, m, n, cnt);
                    grid[pos[0]][pos[1]] = q.front();
                    q.pop();
                }
            }
            m -= 2;
            n -= 2;
            ++cnt;
        }
        return grid;
    }
    
    vector<int> calculatePos(int idx, int m, int n, int cnt) {
        int row, col;
        if (idx < n) {
            row = cnt;
            col = cnt + idx;
        } else if (idx < n + m - 1) {
            row = cnt + idx - n + 1;
            col = cnt + n - 1;
        } else if (idx < 2 * n + m - 2) {
            row = cnt + m - 1;
            col = cnt + n - 1 - (idx - n - m + 2);
        } else {
            row = cnt + 2 * m + 2 * n - 4 - idx;
            col = cnt;
        }
        vector<int> ans{move(row), move(col)};
        return ans;
    }
};
