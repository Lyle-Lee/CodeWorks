class Solution {
private:
    unordered_set<string> deadLocks;

public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        for (auto &s: deadends) {
            deadLocks.insert(s);
        }
        if (deadLocks.count("0000")) return -1;
        queue<string> q1, q2;
        unordered_map<string, int> map1, map2; // to record steps
        q1.emplace("0000");
        q2.push(target);
        map1["0000"] = 0;
        map2[target] = 0;
        while (!q1.empty() && !q2.empty()) {
            int ans;
            if (q1.size() <= q2.size()) ans = update(q1, map1, map2);
            else ans = update(q2, map2, map1);
            if (ans != -1) return ans;
        }
        return -1;
    }

    int update(queue<string>& q, unordered_map<string, int>& cur, unordered_map<string, int>& other) {
        string status = q.front();
        int step = cur[status];
        q.pop();
        auto forward = [](char x) -> char {
            return x == '9' ? '0' : x + 1;
        };
        auto backward = [](char x) -> char {
            return x == '0' ? '9' : x - 1;
        };
        vector<string> nextStatus;
        for (int i = 0; i < 4; ++i) { // enumrate 4 digits
            char digit = status[i];
            status[i] = forward(digit);
            nextStatus.push_back(status);
            status[i] = backward(digit);
            nextStatus.push_back(status);
            status[i] = digit;
        }
        for (auto &s: nextStatus) {
            if (deadLocks.count(s) || cur.count(s)) continue;
            if (other.count(s)) return step + 1 + other[s];
            q.push(s);
            cur[s] = step + 1;
        }
        return -1; // still searching
    }
};
