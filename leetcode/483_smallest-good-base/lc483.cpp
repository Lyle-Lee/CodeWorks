class Solution {
public:
    string smallestGoodBase(string n) {
        long nDec = stol(n);
        int maxLen = floor(log(nDec) / log(2)); // smaller k, larger l, l < log2(n) as k >= 2
        for(int l = maxLen; l > 1; --l) { // total length = l + 1 > 2, else l = 1 (k = nDec - 1)
            int k = pow(nDec, 1.0 / l); // k^l < n < (k + 1)^l, if valid, k must be int part of n^(1/l)
            long mul = 1, sum = 1;
            for (int i = 0; i < l; ++i) {
                mul *= k;
                sum += mul;
            }
            if (sum == nDec) return to_string(k);
        }
        return to_string(nDec - 1);
    }
};
