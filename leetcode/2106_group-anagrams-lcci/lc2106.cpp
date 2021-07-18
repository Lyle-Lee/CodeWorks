class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
        //     return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
        //         return (acc << 1) ^ fn(num);
        //     });
        // };
        // unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        int idx = 0;
        for (auto& str: strs) {
            array<int, 26> cnt{};
            for (auto ch: str) ++cnt[ch - 'a'];
            string key = accumulate(cnt.begin() + 1, cnt.end(), to_string(cnt[0]), [&](string a, int b) {
                return move(a) + '_' + to_string(b);
            });
            auto [iter, check] = mp.insert({key, idx});
            if (check) {
                ++idx;
                ans.emplace_back();
            }
            ans[iter->second].emplace_back(move(str));
            // mp[key].emplace_back(str);
        }
        
        // for (auto& [_, vec]: mp) {
        //     ans.emplace_back(vec);
        // }
        return ans;
    }
};
