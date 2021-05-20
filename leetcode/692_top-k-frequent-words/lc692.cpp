class Solution {
typedef pair<string, int> PSI;

private:
    struct cmp {
        bool operator () (PSI& a, PSI& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (string s : words) {
            ++cnt[s];
        }
        priority_queue<PSI, vector<PSI>, cmp> heap;
        for (auto& it : cnt) {
            heap.emplace(it);
            if (heap.size() > k) heap.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = heap.top().first;
            heap.pop();
        }
        return ans;
    }
};
