class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        
        rows_with_zero = set()
        cols_with_zero = set()
        
        for row in range(len(matrix)):
            for col in range(len(matrix[row])):
                if matrix[row][col] == 0:
                    rows_with_zero.add(row)
                    cols_with_zero.add(col)
        
        for row in rows_with_zero:
            for col in range(len(matrix[row])):
                matrix[row][col] = 0
        
        for col in cols_with_zero:
            for row in range(len(matrix)):
                matrix[row][col] = 0