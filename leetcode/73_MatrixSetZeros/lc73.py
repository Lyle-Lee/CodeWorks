class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        flag = False

        for i in range(m):
            if not matrix[i][0]:
                flag = True
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(m):
            for j in range(1, n):
                if matrix[m-i-1][0] == 0 or matrix[0][j] == 0:
                    matrix[m-i-1][j] = 0
            if flag:
                matrix[m-i-1][0] = 0
