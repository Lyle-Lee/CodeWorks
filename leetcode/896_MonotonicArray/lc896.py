class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) == 1:
            return True
        increase = False
        decrease = False
        for i in range(len(A)-1):
            if A[i] < A[i+1]:
                increase = True
            if A[i] > A[i+1]:
                decrease = True
        return not (increase and decrease)
