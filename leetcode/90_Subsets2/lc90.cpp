class Solution {
public:
    vector<int> subet;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) { // decide which num is selected
            subet.clear();
            bool selected = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) { // add to subset only when current bit is 1
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i-1]) { // give up when previous bit was not selected and current num == previous num
                        selected = false;
                        break;
                    }
                    subet.push_back(nums[i]);
                }
            }
            if (selected) result.push_back(subet);
        }
        return result;
    }
};
