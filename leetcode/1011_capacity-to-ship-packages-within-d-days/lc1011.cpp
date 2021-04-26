class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        if (D == 1) return right;
        while (left < right) {
            int mid = (left + right) / 2;
            int t = 0, cur = 0; // cur: current total weight (arriving)
            for (int w: weights) {
                cur += w;
                if (cur > mid) {
                    t++;
                    cur = w;
                }
            }
            if (t >= D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
