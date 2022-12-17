class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Initialise a stack.
        s = []
        # Traverse the list.
        for token in tokens:
            # Check if we have found a digit or operator.
            if token not in "+-*/":
                s.append(int(token))
            else:
                # Get two digits.
                right, left = s.pop(), s.pop()
                # Perform the operation.
                if token == "+":
                    s.append(left + right)
                elif token == "-":
                    s.append(left - right)
                elif token == "*":
                    s.append(left * right)
                else:
                    s.append(int(float(left) / right))
        return s.pop()