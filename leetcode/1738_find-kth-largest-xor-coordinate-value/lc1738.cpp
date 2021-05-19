class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> preXOR(m + 1, vector<int>(n + 1, 0));
        vector<int> values;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                preXOR[i + 1][j + 1] = preXOR[i][j + 1] ^ preXOR[i + 1][j] ^ preXOR[i][j] ^ matrix[i][j];
                values.push_back(preXOR[i + 1][j + 1]);
            }
        }
        // quick selection
        nth_element(values.begin(), values.begin() + k - 1, values.end(), greater<int>());
        return values[k - 1];
    }
};
