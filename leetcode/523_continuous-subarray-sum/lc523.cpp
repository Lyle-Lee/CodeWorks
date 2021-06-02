class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashTable; // to pair (prefix sum % k) with appear time
        ++hashTable[0];
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            int val = sum + nums[i]; // current prefix sum (right bound)
            // to find a num x: n1 * k + (n2 * k + preSum % k) = (n1 + n2) * k + x = val (n could be 0)
            if (hashTable.count(val % k)) return true;
            ++hashTable[sum % k]; // store last (prefix sum % k) fist to assure min interval
            sum += nums[i];
        }
        return false;
    }
};
