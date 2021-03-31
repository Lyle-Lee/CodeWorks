class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix[0][0] > target || matrix[m-1][n-1] < target) return false;
        int left = 0;
        int right = m * n - 1;
        while (right - left >= 0) {
            int mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
