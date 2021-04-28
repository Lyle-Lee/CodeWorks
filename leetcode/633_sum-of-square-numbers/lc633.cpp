class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = (int)sqrt(c);
        while (a <= b) {
            long judge = a * a + b * b;
            if (judge == c) return true;
            else if (judge < c) a++;
            else if (judge > c) b--;
        }
        return false;
    }
};
