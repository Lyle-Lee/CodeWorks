class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if len(matrix) == 0:
            return None
        self.presum = [[0 for x in range(len(matrix[0])+1)]]
        for i in range(len(matrix)):
            self.presum.append([0])
            for j in range(len(matrix[0])):
                self.presum[i+1].append(self.presum[i][j+1] + self.presum[i+1][j] - 
                                        self.presum[i][j] + matrix[i][j])

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.presum[row2+1][col2+1] - self.presum[row1][col2+1] - self.presum[row2+1][col1] + self.presum[row1][col1]



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
