class Solution:
    def calculate(self, s: str) -> int:
        # Initialise variables to store the current element and its sign.
        num, sign = 0, 1
        # Initialise a stack to store the results.
        st = [0]
        # Traverse the expression.
        for c in s:
            # Check whether the current element is a digit.
            if c.isdigit():
                num = num * 10 + int(c)
            # Check if the current element is a whitespace.
            elif c == ' ':
                continue
            # Check if the current element is a '+'.
            elif c == '+':
                # Update the last element of the stack.
                st[-1] += num * sign
                # Update 'sign' and 'num'.
                sign = 1
                num = 0
            # Check if the current element is a '-'.
            elif c == '-':
                # Update the last element of the stack.
                st[-1] += num * sign
                # Update 'sign' and 'num'.
                sign = -1
                num = 0
            # Check if the current element is a '('.
            elif c == '(':
                # Increase the stack to evaluate the expression inside with correct sign.
                st.extend([sign, 0])
                # Update 'sign' and 'num'.
                sign = 1
                num = 0
            # Check if the current element is a ')'.
            elif c == ')':
                # Update the result and the stack.
                res = (st.pop() + num * sign) * st.pop()
                st[-1] += res
                # Update 'sign' and 'num'.
                sign = 1
                num = 0
        return st[-1] + num * sign