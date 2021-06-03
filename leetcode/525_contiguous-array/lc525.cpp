class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashTable; // to map num of 0 - num of 1 with first appear index
        int n = nums.size(), diff = 0, ans = 0;
        hashTable[0] = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) ++diff;
            else --diff;
            if (hashTable.count(diff)) {
                ans = max(ans, i - hashTable[diff]);
            } else {
                hashTable[diff] = i;
            }
        }
        return ans;
    }
};
