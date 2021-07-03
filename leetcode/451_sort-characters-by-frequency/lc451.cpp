class Solution {
public:
    string frequencySort(string s) {
        // bucket sort in comment part
        unordered_map<char, int> map;
        // int maxFreq = 0;
        for (auto &c: s) {
            // maxFreq = max(maxFreq, ++map[c]);
            ++map[c];
        }
        vector<string> strArray;
        // vector<string> bucket(maxFreq + 1);
        for (auto &[c, cnt]: map) {
            string word = "";
            for (int i = 0; i < cnt; ++i) word += c;
            strArray.push_back(word);
            // bucket[cnt].push_back(c);
        }
        sort(strArray.begin(), strArray.end(), [](auto &a, auto &b) {
            return a.length() > b.length();
        });
        string ans;
        for (auto &str: strArray) {
            ans += str;
        }
        /*
        for (int i = maxFreq; i >= 1; --i) {
            for (auto &c: bucket[i]) {
                for (int j = 0; j < i; ++j) {
                    ans += c;
                }
            }
        }
        */
        return ans;
    }
};
