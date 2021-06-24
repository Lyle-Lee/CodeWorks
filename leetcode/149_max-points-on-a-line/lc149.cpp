class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (n - i == ans || ans > n / 2) break;
            unordered_map<int, int> hashMap;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int dx = x1 - points[j][0], dy = y1 - points[j][1];
                if (dx == 0) dy = 1;
                else if (dy == 0) dx = 1;
                else {
                    if (dy < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    int GCD = gcd(abs(dx), abs(dy));
                    dx /= GCD;
                    dy /= GCD;
                }
                int k = dy + 20000 * dx; // 0 <= dy <= 20000
                ++hashMap[k];
                if (hashMap[k] > ans) ans = hashMap[k];
            }
        }
        return ans + 1;
    }

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};
