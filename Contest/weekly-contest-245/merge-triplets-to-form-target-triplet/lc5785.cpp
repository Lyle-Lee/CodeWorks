class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = 0, b = 0, c = 0;
        int x = target[0], y = target[1], z = target[2];
        for (auto &t: triplets) {
            if (t[0] <= x && t[1] <= y && t[2] <= z) {
                tie(a, b, c) = tuple{max(a, t[0]), max(b, t[1]), max(c, t[2])};
            }
        }
        return tie(a, b, c) == tie(x, y, z);
    }
};
