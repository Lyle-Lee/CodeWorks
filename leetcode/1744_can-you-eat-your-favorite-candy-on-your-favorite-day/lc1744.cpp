class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int typeNum = candiesCount.size();
        vector<long> preSum(typeNum + 1, 0);
        for (int i = 0; i < typeNum; ++i) {
            preSum[i + 1] = preSum[i] + candiesCount[i];
        }
        vector<bool> ans;
        for (auto& q: queries) {
            ans.push_back(q[1] + 1 <= preSum[q[0] + 1] && (long)q[2] * (q[1] + 1) > preSum[q[0]]);
        }
        return ans;
    }
};
