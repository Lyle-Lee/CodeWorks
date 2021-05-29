class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        bool row_mode = n >= m;
        for (int i = 0; i < (row_mode ? m : n); ++i) {
            vector<int> sum(row_mode ? n : m, 0); // area sum: 2D -> 1D
            for (int j = i; j < (row_mode ? m : n); ++j) {
                for (int x = 0; x < (row_mode ? n : m); ++x) {
                    sum[x] += row_mode ? matrix[j][x] : matrix[x][j];
                }
                // hashTable to map prefix sum of left (top) boundary and appear times
                unordered_map<int, int> preSum;
                int cur = 0; // prefix sum of right (bottom) boundary
                for (int val: sum) {
                    cur += val;
                    if (cur == target) ++ans;
                    // to find a value x: cur - x = target
                    if (preSum.count(cur - target)) ans += preSum[cur - target];
                    ++preSum[cur];
                }
            }
        }
        return ans;
    }
};
