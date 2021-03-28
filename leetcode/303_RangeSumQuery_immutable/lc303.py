class NumArray:

    def __init__(self, nums: List[int]):
        self.NumArray = nums
        self.presum = [0]
        add = 0
        for i in range(len(nums)):
            add += nums[i]
            self.presum.append(add)


    def sumRange(self, i: int, j: int) -> int:
        return self.presum[j+1] - self.presum[i]



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
