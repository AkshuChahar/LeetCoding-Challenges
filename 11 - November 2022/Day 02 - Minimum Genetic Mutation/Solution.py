class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        # Initialise a queue for 'BFS' and a set to keep track of visited strings.
        q = deque([(start, 0)])
        vis = {start}
        # Do a 'BFS'.
        while q:
            s, ans = q.popleft()
            # Check if we have arrived at the end.
            if s == end:
                return ans
            # Check for each character.
            for c in "ACGT":
                for i in range(len(s)):
                    temp = s[:i] + c + s[i + 1:]
                    if temp not in vis and temp in bank:
                        q.append((temp, ans + 1))
                        vis.add(temp)
        return -1