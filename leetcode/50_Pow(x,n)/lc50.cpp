class Solution {
public:
    double fastMul(double x, long long N) {
        double res = 1.0;
        double x_contribute = x; // initial contribute
        while (N > 0) {
            if (N & 1 == 1) { // contribute to result if current(last) bit is 1
                res *= x_contribute;
            }
            x_contribute *= x_contribute; // divide N to 2 parts; O(logn)
            N = N >> 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        long long N = n;
        return n >= 0 ? fastMul(x, N) : 1.0 / fastMul(x, -N);
    }
};
