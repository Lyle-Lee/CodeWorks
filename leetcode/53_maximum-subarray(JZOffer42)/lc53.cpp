class Solution {
private:
    struct Status {
        int lMaxSum, rMaxSum, totalSum, maxSum;
    };
    
public:
    int maxSubArray(vector<int>& nums) {
        return getMaxSum(nums, 0, nums.size() - 1).maxSum;
    }

    Status pushUp(Status l, Status r) {
        int total = l.totalSum + r.totalSum;
        int lSum = max(l.lMaxSum, l.totalSum + r.lMaxSum);
        int rSum = max(r.rMaxSum, r.totalSum + l.rMaxSum);
        int mSum = max(max(l.maxSum, r.maxSum), l.rMaxSum + r.lMaxSum);
        return (Status) {lSum, rSum, total, mSum};
    }

    Status getMaxSum(vector<int>& nums, int l, int r) {
        if (l == r) return (Status) {nums[l], nums[l], nums[l], nums[l]};
        int mid = l + r >> 1;
        Status lPart = getMaxSum(nums, l, mid);
        Status rPart = getMaxSum(nums, mid + 1, r);
        return pushUp(lPart, rPart);
    }
};
