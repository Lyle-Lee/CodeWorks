class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3);
        int n = stones.size();
        for (int i = 0; i < n; ++i) {
            ++freq[stones[i] % 3];
        }
        if (freq[0] % 2 == 0) return freq[1] > 0 && freq[2] > 0;
        return max(freq[1], freq[2]) - min(freq[1], freq[2]) > 2;
    }
};
