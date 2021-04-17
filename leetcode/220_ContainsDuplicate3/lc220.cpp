class Solution {
public:
    int getID(int x, long width) {
        return x >= 0 ? x / width : (x + 1) / width - 1;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<int, int> bucket;
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1L);
            if (bucket.count(id)) return true; // target element exists in the same bucket
            if (bucket.count(id - 1) && abs(x - bucket[id - 1]) <= t) return true; // check left bucket
            if (bucket.count(id + 1) && abs(x - bucket[id + 1]) <= t) return true; // check right bucket
            bucket[id] = x;
            if (i >= k) bucket.erase(getID(nums[i - k], t + 1L));
        }
        return false;
    }
};
