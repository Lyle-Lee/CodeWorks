class Solution {
    const int maxNum = 31;
    inline static unordered_map<int, unordered_set<int>> factors;
    unordered_set<int> invalid = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
    const int MOD = 1e9 + 7;

public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int ans = 0, freq[maxNum], last = 0;
        memset(freq, 0, sizeof(freq));
        for (auto& num: nums) {
            ++freq[num];
            last = max(num, last);
        }
        function<void(vector<int>, int, long)> dfs = [&](vector<int> res, int cur, long product) {
            if (cur == last + 1) {
                if (res.empty()) return;
                int cnt = 1;
                for (auto& num: res) {
                    cnt = ((long)cnt * freq[num]) % MOD;
                }
                ans = (ans + cnt) % MOD;
                return;
            }
            if (freq[cur] && !invalid.count(cur)) {
                if (factors[cur].empty()) updateFactor(cur);
                bool check = true;
                for (auto& fac: factors[cur]) {
                    if (product % fac == 0) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    res.push_back(cur);
                    dfs(res, cur + 1, product * cur);
                    res.pop_back();
                }
            }
            dfs(res, cur + 1, product);
        };
        dfs({}, 2, 1);
        if (ans == 0) return 0;
        if (freq[1]) ans = ((long)ans * fastPow(freq[1])) % MOD;
        return ans;
    }

    void updateFactor(int num) {
        int factor = 2;
        while (factor * factor < num) {
            if (num % factor == 0) {
                if (factors[factor].empty()) updateFactor(factor);
                for (auto& fac: factors[factor]) factors[num].insert(fac);
                int dev = num / factor;
                if (factors[dev].empty()) updateFactor(dev);
                for (auto& fac: factors[dev]) factors[num].insert(fac);
                break;
            }
            ++factor;
        }
        if (factors[num].empty()) factors[num].insert(num);
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
