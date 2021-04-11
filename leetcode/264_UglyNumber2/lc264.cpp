class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ug_num(n, 1);
        int p2 = 0, p3 = 0, p5 = 0; // pointers
        for (int i = 1; i < n; ++i) {
            int num2 = ug_num[p2] * 2, num3 = ug_num[p3] * 3, num5 = ug_num[p5] * 5;
            ug_num[i] = min(min(num2, num3), num5); // the next ugly number
            if (ug_num[i] == num2) p2++;
            if (ug_num[i] == num3) p3++;
            if (ug_num[i] == num5) p5++;
        }
        return ug_num[n-1];
    }
};
