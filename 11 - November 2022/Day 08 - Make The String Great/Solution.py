class Solution:
    def makeGood(self, s: str) -> str:
        # Initialise a stack.
        st = []
        # Traverse the string.
        for ch in s:
            # Check if the given condition is satisfied.
            if st and st[-1] == ch.swapcase():
                st.pop()
            else:
                st.append(ch)
        return "".join(st)