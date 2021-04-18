// The 4-th problem of 🐱 50th.

class Solution {
private:
    const int mod = 1e9 + 7;

public:
    int quickExp(int x, int N) {
        long long res = 1;
        long long x_contribute = x; // initial contribute
        while (N > 0) {
            if (N & 1 == 1) { // contribute to result if current(last) bit is 1
                res = res * x_contribute % mod;
            }
            x_contribute = x_contribute * x_contribute % mod; // divide N to 2 parts; O(logn)
            N = N >> 1;
        }
        return res;
    }

    int mulInv(int x) {
    // multiplicative inverse element: x * mulInv(x) = 1 (mod m);
    // apply Fermat's little theorem: x^{m - 1} = 1 (mod m) -> mulInv(x) = x^{m - 2}
        return quickExp(x, mod - 2);
    }

    int makeStringSorted(string s) {
        int n = s.length();
        vector<int> fac(n + 1), fac_inv(n + 1);
        fac[0] = fac_inv[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fac[i] = (long long)fac[i - 1] * i % mod;
            fac_inv[i] = mulInv(fac[i]);
        }
        int answer = 0;
        vector<int> freq(26); // frequency of elements in s
        for (char ch: s) {
            ++freq[ch - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            int rank = 0; // nums of characters which smaller than s[i]
            for (int j = 0; j < s[i] - 'a'; ++j) {
                rank += freq[j];
            }
            if (rank) {
                int cur = (long long)rank * fac[n - 1 - i] % mod;
                for (int j = 0; j < 26; ++j) {
                    cur = (long long)cur * fac_inv[freq[j]] % mod;
                }
                answer = (cur + answer) % mod;
            }
            --freq[s[i] - 'a'];
        }
        return answer;
    }
};
