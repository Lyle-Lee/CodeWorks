class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorRes = x ^ y;
        int ans = 0;
        while (xorRes > 0) {
            ++ans;
            xorRes &= xorRes - 1; // set the lowest 1 to 0
        }
        return ans;
    }
};
