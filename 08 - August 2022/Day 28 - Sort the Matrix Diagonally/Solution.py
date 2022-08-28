class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        # Initialise a dictionary to store the diagonal arrays.
        diagonal = defaultdict(list)
        # Put the diagonal arrays in the dictionary.
        for i in range(m):
            for j in range(n):
                diagonal[i - j].append(mat[i][j])
        # Sort the arrays in descending order.
        for arr in diagonal:
            diagonal[arr].sort(reverse = True)
        # Put the elements back in the matrix in sorted order.
        for i in range(m):
            for j in range(n):
                mat[i][j] = diagonal[i - j].pop()
        return mat