class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        row, col, ans = len(matrix), len(matrix[0]), float(inf)
        # Traverse the matrix.
        for i in range(1, row):
            for j in range(col):
                # Update the matrix.
                if j == 0:
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1])
                elif j == col - 1:
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1])
                else:
                    matrix[i][j] += min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i-1][j+1]))
        # Update 'ans'.
        for i in range(col):
            ans = min(ans, matrix[row - 1][i])
        return ans