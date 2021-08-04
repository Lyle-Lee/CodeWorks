class Solution {
public:
    int crossProduct(vector<int>& A, vector<int>& B, vector<int>& C) {
        return (A[0] - B[0]) * (A[1] - C[1]) - (A[1] - B[1]) * (A[0] - C[0]);
    }

    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int sign = 0;
        for (int i = 0; i < n; ++i) {
            int cp = crossProduct(points[i % n], points[(i + 1) % n], points[(i + 2) % n]);
            if (cp != 0) {
                if (sign * cp < 0) return false;
                if (sign == 0) sign = cp > 0 ? 1 : -1;
            }
        }
        return true;
    }
};
