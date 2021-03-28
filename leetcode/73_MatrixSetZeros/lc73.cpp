class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> index;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (index.size() == 0) {
                        vector<int> new_element;
                        new_element.push_back(i);
                        new_element.push_back(j);
                        index.push_back(new_element);
                    } else {
                        int added = 0;
                        for (int k = 0; k < index.size(); k++) {
                            if (index[k][0] == i) {
                                added = 1;
                                index[k].push_back(j);
                            }
                        }
                        if (added == 0) {
                            vector<int> new_element;
                            new_element.push_back(i);
                            new_element.push_back(j);
                            index.push_back(new_element);
                        }
                    }
                }
            }
        }
        if (index.size() == 0) return;
        for (int i = 0; i < index.size(); i++) {
            int row = index[i][0];
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
            for (int j = 1; j < index[i].size(); j++) {
                int col = index[i][j];
                for (int k = 0; k < m; k++) {
                    matrix[k][col] = 0;
                }
            }
        }
    }
};
