class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        // stack<vector<int>> stk;
        // stk.push(properties[0]);
        int defense = properties[0][1], attack = properties[0][0], ans = 0;
        for (int i = 1; i < n; ++i) {
            // if (properties[i][0] == stk.top()[0] || properties[i][1] >= stk.top()[1]) {
            //     stk.push(properties[i]);
            // }
            if (properties[i][0] == attack || properties[i][1] >= defense) {
                attack = properties[i][0];
                defense = properties[i][1];
            } else {
                ++ans;
            }
        }
        // return n - stk.size();
        return ans;
    }
};
