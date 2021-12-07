class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if (grid[row][col] == color) return grid;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n, 0));
        vector<int> dir = {1, 0, -1, 0, 1};
        int linkColor = grid[row][col];
        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = 1;
            bool isBoundary = false;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                bool valid = nx >= 0 && nx < m && ny >= 0 && ny < n;
                if (valid && visited[nx][ny]) continue;
                if (valid && grid[nx][ny] == linkColor) dfs(nx, ny);
                else isBoundary = true;
            }
            if (isBoundary) grid[x][y] = color;
        };
        dfs(row, col);
        return grid;
    }
};
