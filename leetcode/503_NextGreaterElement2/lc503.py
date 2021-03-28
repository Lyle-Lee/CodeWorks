class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0:
            return None
        #cur_max = nums[-1]
        #index = [n - 1]
        answer = [-1] * n
        #for i in range(1, n):
        #    if cur_max <= nums[-1-i]:
        #        cur_max = nums[-1-i]
        #        index.append(n - 1 - i)
        #    elif cur_max > nums[-1-i]:
        #        for j in range(n-i, index[-1]+1):
        #            if nums[j] == nums[-1-i]:
        #                answer[-1-i] = answer[j]
        #                break
        #            elif nums[j] > nums[-1-i]:
        #               answer[-1-i] = nums[j]
        #               break
        #   for ids in index[:-1]:
        #       if nums[-1-i] > nums[ids]:
        #           answer[ids] = nums[-1-i]

        stack = []

        for i in range(n * 2 - 1):
            while stack and nums[stack[-1]] < nums[i % n]:
                answer[stack.pop()] = nums[i % n]
            stack.append(i % n)

        return answer
