class Solution:
    def removeDuplicates(self, s: str) -> str:
        # Initialise a stack.
        st = []
        # Traverse the string.
        for ch in s:
            # Check if we same adjacent characters.
            if st and st[-1] == ch:
                st.pop()
            else:
                st.append(ch)
        return "".join(st)