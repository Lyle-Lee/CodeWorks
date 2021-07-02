class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(1e5 + 1, 0);
        for (int cost: costs) {
            ++freq[cost];
        }
        int ans = 0;
        for (int i = 1; i <= 1e5; ++i) {
            if (i > coins) break;
            if (freq[i] == 0) continue;
            int cnt = min(freq[i], coins / i);
            ans += cnt;
            coins -= cnt * i;
        }
        return ans;
    }
};
