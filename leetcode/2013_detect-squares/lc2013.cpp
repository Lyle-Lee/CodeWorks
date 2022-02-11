class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> mp;
    const int max_pos = 1000;

public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        ++mp[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        if (mp[point[0]].empty()) return 0;
        int ans = 0;
        for (auto& [y, cnt]: mp[point[0]]) {
            if (y == point[1]) continue;
            int len = abs(y - point[1]);
            int x1 = point[0] - len, x2 = point[0] + len;
            if (x1 >= 0 && mp[x1].count(y) && mp[x1].count(point[1])) {
                ans += cnt * mp[x1][y] * mp[x1][point[1]];
            }
            if (x2 <= max_pos && mp[x2].count(y) && mp[x2].count(point[1])) {
                ans += cnt * mp[x2][y] * mp[x2][point[1]];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
