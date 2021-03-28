class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row_mode = 0;
        int col_mode = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m;
        int col = n;
        while (result.size() < row * col) {
            if (row_mode == 0 && col_mode == 0) {
                for (int i = row-m; i < n; i++) {
                    result.push_back(matrix[row-m][i]);
                }
                row_mode = 1;
            } else if (row_mode == 1 && col_mode == 0) {
                for (int i = 1+row-m; i < m; i++) {
                    result.push_back(matrix[i][n-1]);
                }
                col_mode = 1;
            } else if (row_mode == 1 && col_mode == 1) {
                for (int i = n-2; i >= col-n; i--) {
                    result.push_back(matrix[m-1][i]);
                }
                row_mode = 0;
                m--;
            } else {
                for (int i = m-1; i >= row-m; i--) {
                    result.push_back(matrix[i][col-n]);
                }
                col_mode = 0;
                n--;
            }
        }
        return result;
    }
};
