class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        # Initialise a stack.
        st = []
        ans, n = 0, len(arr)
        # Traverse the array.
        for i in range(len(arr) + 1): 
            while st and (i == n or arr[st[-1]] >= arr[i]):
                # Update the stack and the sum.
                mid = st.pop()
                left_boundary = -1 if not st else st[-1]
                right_boundary = i
                count = (mid - left_boundary) * (right_boundary - mid)
                ans += (count * arr[mid])
            st.append(i)
        return ans % MOD