# Class to implement 'Trie'.
class Trie:
    def __init__(self, words=[]):
        self.trie = {}
        # Insert all the words in the 'Trie'.
        for w in words: 
            self.insert(w)
    # Function to insert the words.
    def insert(self, word):
        # Initialise an object.
        t = self.trie
        # Traverse the 'word'.
        for w in word:
            if w not in t:
                t[w] = {}
            t = t[w]
        t['#'] = '#'
    # Function to search for a word in the trie.
    def search(self, word):
        # Initialise an object.
        t = self.trie
        # Traverse the 'word'.
        for w in word:
            if w not in t:
                return False
            t = t[w]
        if '#' in t:
            return True
        return False
    # Function for prefix search.
    def starts(self, prefix):
        # Initialise an object.
        t = self.trie
        # Traverse the 'prefix'.
        for w in prefix:
            if w not in t:
                return False
            t = t[w]
        return True
    # Function to remove a word.
    def remove(self, word):
        # Initialise an object.
        t = self.trie
        nodes = []
        # Traverse the 'word'.
        for w in word:
            if w not in t:
                return False
            t = t[w]
            nodes.append((t,w))
        if '#' in t:
            p = '#'
            for n, w in nodes[::-1]:
                if len(n[p]) == 0 or p == '#' : 
                    del n[p]
                p = w 

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m, n = len(board), len(board[0])
        # Initialise a 'Trie' and a set to keep track of visited words.
        trie = Trie(words)
        vis = set()       
        # Generator that yields '!' for adjacent cells.
        def adj(x, y):
            for i, j in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                if 0 <= x + i < m and 0 <= y + j < n:
                    yield (x + i, y + j)
        # Function for 'DFS'.
        def dfs(p, b, x, y):          
            # Mark the cell as used.
            ch, b[x][y] = b[x][y], "#"
            # Check if the word has been visited.
            if trie.search(p):               
                vis.add(p)
                trie.remove(p)
            # Iterate over adjacent cells.
            for i, j in adj(x, y):
                if b[i][j] != "#":
                    pp = p + b[i][j]
                    if trie.starts(pp):
                        dfs(pp, b, i, j)
            # Backtrack.
            b[x][y] = ch
        # Perform 'DFS'.
        for i in range(m):
            for j in range(n):
                dfs(board[i][j], board, i, j)
        return vis