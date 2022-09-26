class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        # Build the parent list.
        par = [i for i in range(26)]
        # Function for 'Union Find'.
        def find(c):
            if par[c] == c:
                return c
            par[c] = find(par[c])
            return par[c]
        # Traverse the given list and build the relationships.
        for eq in equations:
            # Check if the the case is of '=='.
            if eq[1] == '=':
                par[find(ord(eq[0]) - ord('a'))] = find(ord(eq[3]) - ord('a'))
        # Check if there are any contradictory relationships.
        for eq in equations:
            if eq[1] == '!' and find(ord(eq[0]) - ord('a')) == find(ord(eq[3]) - ord('a')):
                return False
        return True