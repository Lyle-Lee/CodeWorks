class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = arr.size();
        vector<int> preXOR(m + 1);
        preXOR[0] = 0;
        for (int i = 0; i < m; ++i) {
            preXOR[i + 1] = preXOR[i] ^ arr[i];
        }
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = preXOR[queries[i][1] + 1] ^ preXOR[queries[i][0]];
        }
        return ans;
    }
};
