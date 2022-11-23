class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Initialise a list to store the visited cells.
        vis = []
        # Traverse the board.
        for i, row in enumerate(board):
            for j, ele in enumerate(row):
                # Check if we have found a digit.
                if ele != ".":
                    vis.extend([(ele, i), (j, ele), (ele, i//3, j//3)])
        return len(set(vis)) == len(vis)