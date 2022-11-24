class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        # Edge case: Check if the length of word is grester than the board size.
        if len(word) > m * n:
            return False
        # Count the frequency of each character.
        freq = Counter(word)
        # Reverse the word.
        if freq[word[0]] > freq[word[-1]]:
            word = word[::-1]
        # Function for 'DFS'.
        def dfs(i, j, s):
            # Check if we have found the word.
            if s == len(word):
                return True
            # Check if we have found a letter.
            if 0 <= i < m and 0 <= j < n and board[i][j] == word[s]:
                # Mark the current element as visited.
                board[i][j] = "#"
                # Move in every direction.
                adj = [(i, j + 1), (i, j - 1), (i + 1, j), (i - 1, j)]
                dp = any(dfs(ii, jj, s + 1) for ii, jj in adj)
                board[i][j] = word[s]
                return dp
            return False
        return any(dfs(i, j, 0) for i, j in product(range(m), range(n)))