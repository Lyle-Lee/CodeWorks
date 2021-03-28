class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int row_mode = 0;
        int col_mode = 0;
        int m = n;
        int row = m;
        int col = n;
        int num = 1;
        while (num <= row * col) {
            if (row_mode == 0 && col_mode == 0) {
                for (int i = row-m; i < n; i++) {
                    matrix[row-m][i] = num;
                    num++;
                }
                row_mode = 1;
            } else if (row_mode == 1 && col_mode == 0) {
                for (int i = 1+row-m; i < m; i++) {
                    matrix[i][n-1] = num;
                    num++;
                }
                col_mode = 1;
            } else if (row_mode == 1 && col_mode == 1) {
                for (int i = n-2; i >= col-n; i--) {
                    matrix[m-1][i] = num;
                    num++;
                }
                row_mode = 0;
                m--;
            } else {
                for (int i = m-1; i >= row-m; i--) {
                    matrix[i][col-n] = num;
                    num++;
                }
                col_mode = 0;
                n--;
            }
        }
        return matrix;
    }
};
