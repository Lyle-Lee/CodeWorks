class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int pile: piles) {
            pq.push(pile);
        }
        while (k > 0) {
            int target = pq.top();
            pq.pop();
            target = target - target / 2;
            pq.push(target);
            --k;
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
