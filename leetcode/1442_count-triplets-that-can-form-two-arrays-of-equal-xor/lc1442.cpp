class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        //vector<int> preXOR(n + 1, 0);
        //for (int i = 1; i <= n; ++i) {
        //    preXOR[i] = preXOR[i - 1] ^ arr[i - 1];
        //}
        int ans = 0;
        //for (int i = 0; i <= n; ++i) { // find interval arr[i + 1] xor ... xor arr[k - 1] = 0
        //    for (int k = i + 2; k <= n; ++k) {
        //        if (preXOR[k] == preXOR[i]) ans += k - 1 - i; // num of possible 'j's
        //    }
        //}
        unordered_map<int, int> cnt, total;
        int preXOR = 0;
        for (int i = 0; i <= n; ++i) {
            if (cnt[preXOR]) ans += cnt[preXOR] * (i - 1) - total[preXOR]; // i - 1 here is k (index)
            ++cnt[preXOR]; // num of appearance of the same preXOR
            if (i < n) {
                total[preXOR] += i; // sum of index of the same preXOR
                preXOR ^= arr[i];
            }
        }
        return ans;
    }
};
