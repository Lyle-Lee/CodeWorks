class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> tree(n);
        vector<int> childCnt(n);
        for (int i = 1; i < n; ++i) {
            tree[parents[i]].push_back(i);
        }
        stack<int> stk;
        stk.push(0);
        long maxPoint = 0;
        int ans = 0;
        while (!stk.empty()) {
            int cur = stk.top();
            if (cur != -1) {
                int numChild = tree[cur].size();
                stk.push(-1);
                if (numChild) {
                    stk.push(tree[cur][0]);
                    if (numChild > 1) stk.push(tree[cur][1]);
                }
            } else {
                stk.pop();
                int node = stk.top();
                for (int child: tree[node]) childCnt[node] += childCnt[child];
                ++childCnt[node];
                stk.pop();
                int p1 = n - childCnt[node];
                int p2 = tree[node].size() > 0 ? childCnt[tree[node][0]] : 0;
                int p3 = tree[node].size() > 1 ? childCnt[tree[node][1]] : 0;
                long point = (long)(p1 > 0 ? p1 : 1) * (p2 > 0 ? p2 : 1) * (p3 > 0 ? p3 : 1);
                if (point > maxPoint) {
                    maxPoint = point;
                    ans = 1;
                } else if (point == maxPoint) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
