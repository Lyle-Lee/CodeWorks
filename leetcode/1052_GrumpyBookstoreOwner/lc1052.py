class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        max_s = 0
        #start = 0
        result = 0
        satisfied = 0
        for i in range(len(customers)): # find best interval
            if grumpy[i] == 1:
                satisfied += customers[i]
            if i >= X and grumpy[i-X] == 1:
                satisfied -= customers[i-X]
            if max_s < satisfied:
                max_s = satisfied
                #start = i - 2
        for i in range(len(customers)): # calculate result
            if grumpy[i] == 0:
                result += customers[i]
        result += max_s
        return result
