class Solution {
    const int maxNum = 31;
    inline static vector<int> states = {0};
    unordered_map<int, int> factors = {{2, 0}, {3, 1}, {5, 2}, {7, 3}, {11, 4}, {13, 5}, {17, 6}, {19, 7}, {23, 8}, {29, 9}};
    unordered_set<int> invalid = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
    const int MOD = 1e9 + 7;

public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int freq[maxNum], last = 1;
        memset(freq, 0, sizeof(freq));
        for (auto& num: nums) {
            ++freq[num];
            last = max(num, last);
        }
        if (last == 1) return 0;
        int total = 1 << factors.size();
        vector<int> dp(total);
        dp[0] = fastPow(freq[1]);
        for (int i = 2; i <= last; ++i) {
            if (invalid.count(i)) {
                if (states.size() < i) states.push_back(0);
                continue;
            }
            if (states.size() < i) updateFactor(i);
            if (!freq[i]) continue;
            for (int mask = total - 1; mask > 0; --mask) {
                if ((mask | states[i - 1]) != mask) continue;
                dp[mask] = (dp[mask] + ((long)dp[mask ^ states[i - 1]] * freq[i]) % MOD) % MOD;
            }
        }
        int ans = 0;
        for (int i = 1; i < total; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }

    void updateFactor(int num) {
        if (factors.count(num)) {
            states.push_back(1 << factors[num]);
            return;
        }
        int factor = 2, mask = 0;
        while (factor * factor < num) {
            if (num % factor == 0) {
                mask = states[factor - 1] | states[num / factor - 1];
                break;
            }
            ++factor;
        }
        states.push_back(mask);
    }

    int fastPow(int p) {
        int ans = 1, x = 2;
        while (p > 0) {
            if (p & 1) ans = ((long)ans * x) % MOD;
            x = ((long)x * x) % MOD;
            p >>= 1;
        }
        return ans;
    }
};
