class Solution {
public:
    bool canMake(vector<int>& nums, int day, int m, int k) {
        int bouquet = 0;
        int flower = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= day) {
                flower++; // can pick
                if (flower == k) { // can make a new bouquet
                    bouquet++;
                    flower = 0;
                }
            } else {
                flower = 0; // new interval
            }
            if (bouquet == m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        int left = INT_MAX, right = 0;
        for (int i = 0; i < n; ++i) {
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (canMake(bloomDay, mid, m, k)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
