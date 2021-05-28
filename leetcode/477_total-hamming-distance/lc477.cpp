class Solution {
private:
    const int maxBit = 30;

public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < maxBit; ++i) {
            int cnt = 0; // count if current bit is 1
            for (int j = 0; j < n; ++j) {
                cnt += (nums[j] >> i) & 1;
            }
            ans += cnt * (n - cnt); // n - cnt: num of 0 bit(s)
        }
        return ans;
    }
};
