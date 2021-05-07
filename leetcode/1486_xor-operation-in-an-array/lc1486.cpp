class Solution {
public:
    int sumXOR(int x) {
        // calculate 1 xor 2 xor ... xor x
        // 1 xor 2 xor 3 = 0
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0; // includes x < 0 (cases that start = 0 or 1)
    }

    int xorOperation(int n, int start) {
        // every time dummy_start += 1; e = result of lowest bit
        int dummy_start = start >> 1, e = n & start & 1;
        int half = sumXOR(dummy_start - 1) ^ sumXOR(dummy_start + n - 1); // a xor (a xor b) = b
        return half << 1 | e;
    }
};
