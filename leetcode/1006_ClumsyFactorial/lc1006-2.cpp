class Solution {
public:
    int clumsy(int N) {
        if (N <= 4) {
            int result = N;
            int count = 1;
            N--;
            while (N) {
                if (count == 1) result *= N;
                else if (count == 2) result /= N;
                else result += N;
                N--;
                count++;
            }
            return result;
        } else { // N * (N-1) / (N-2) = N + 1 while N > 4; (N-3) - (N-4) * (N-5) / (N-6) = 0 while N > 8
            if (N % 4 == 0) return N + 1;
            else if (N % 4 == 1 || N % 4 == 2) return N + 2;
            else return N - 1;
        }
    }
};
