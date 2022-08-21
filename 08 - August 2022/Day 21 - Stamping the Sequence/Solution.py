class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        m, n = len(stamp), len(target)
        ans = []
        initial = '#' * n
        pos = n - m
        # Initialise a set to store every combination possible for 'stamp'.
        st = set()
        for i in range(m):
            for j in range(m - i):
                st.add('#' * i + stamp[i : m - j] + '#' * j)
        # Iterate untill we reach back to 'initial' string.
        while target != initial:
            flag = False
            # Check in the backward direction.
            for i in range(pos, -1, -1):
                # Check if we have found a combination of 'stamp'.
                if target[i : i + m] in st:
                    # Update 'target' and add the index to resulting array.
                    target = target[:i] + '#' * m + target[i + m:]
                    ans.append(i)
                    flag = True
            # Check if the starting string cannot be obtained.
            if not flag:
                return []
        return ans[::-1]