class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, minCnt = 0;
        for (char& ch: s) {
            if (ch == '[') ++cnt;
            else --cnt;
            minCnt = min(minCnt, cnt);
        }
        return minCnt / 2 - minCnt;
    }
};
