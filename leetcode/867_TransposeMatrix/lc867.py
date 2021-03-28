class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        add = abs(m - n)
        for i in range(min(m, n)): # first deal with symmetric part
            for j in range(min(m, n)-i-1):
                tmp = matrix[i][i+j+1]
                matrix[i][i+j+1] = matrix[i+j+1][i]
                matrix[i+j+1][i] = tmp
        if m == n:
            return matrix
        if m > n:
            for i in range(n):
                for j in range(add):
                    matrix[i].append(matrix[n+j][i])
            matrix = matrix[:n]
        else:
            for i in range(add):
                vec = []
                for j in range(m):
                    vec.append(matrix[j][m+i])
                matrix.append(vec)
            for i in range(m):
                matrix[i] = matrix[i][:m]
        return matrix
