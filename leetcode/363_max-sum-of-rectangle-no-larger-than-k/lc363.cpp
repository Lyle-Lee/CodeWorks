class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int answer = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        bool row_mode = n >= m;
        for (int i = 0; i < (row_mode ? m : n); ++i) {
            vector<int> sum(row_mode ? n : m, 0); // area sum: 2D -> 1D
            for (int j = i; j < (row_mode ? m : n); ++j) {
                for (int x = 0; x < (row_mode ? n : m); ++x) {
                    sum[x] += row_mode ? matrix[j][x] : matrix[x][j];
                }
                set<int> pre_sum{0}; // tree set to store prefix sum of left (top) boundary
                int r = 0; // prefix sum of right (bottom) boundary
                for (int val: sum) {
                    r += val;
                    auto l = pre_sum.lower_bound(r - k); // l = argmin(pre_sum[l] >= r - k)
                    if (l != pre_sum.end()) { // found valid
                        answer = max(answer, r - *l);
                    }
                    pre_sum.insert(r);
                }
            }
        }
        return answer;
    }
};
