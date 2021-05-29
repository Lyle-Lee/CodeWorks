class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // hashTable to map prefix sum of left boundary and appear times
        unordered_map<int, int> preSum;
        int cur = 0; // prefix sum of right boundary
        int ans = 0;
        for (int val: nums) {
            cur += val;
            if (cur == k) ++ans;
            if (preSum.count(cur - k)) ans += preSum[cur - k]; // to find a value x: cur - x = k
            ++preSum[cur];
        }
        return ans;
    }
};
