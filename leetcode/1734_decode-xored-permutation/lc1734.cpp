class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1; // n is odds
        int total;
        if (n % 4 == 1) total = 1;
        else total = 0; // n % 4 == 3, 1 xor 2 xor 3 = 0
        int odd = 0;
        // perm[0] xor (perm[1] xor perm[2] xor ... xor perm[n-1]) = total
        // perm[1] xor perm[2] = encoded[1], ..., perm[n-2] xor perm[n-1] = encoded[n-2]
        for (int i = 1; i < n - 1; i += 2) {
            odd ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ odd;
        for (int i = 1; i < n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm;
    }
};
