class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<int, int> map{{0, 1}};
        int mask = 0; // prefix mask
        for (char c: word) {
            int idx = c - 'a';
            mask ^= (1 << idx);
            if (map.count(mask)) ans += map[mask];
            for (int i = 0; i < 10; ++i) {
                int maskFlip = mask ^ (1 << i);
                if (map.count(maskFlip)) ans += map[maskFlip];
            }
            ++map[mask];
        }
        return ans;
    }
};
