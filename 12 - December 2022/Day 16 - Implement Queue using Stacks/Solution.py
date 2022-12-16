
class MyQueue:

    def __init__(self):
        # Initialise the stacks.
        self.st1, self.st2 = [], []

    def push(self, x: int) -> None:
        # Add the element to the stack.
        self.st1.append(x)

    def pop(self) -> int:
        # Check if the second stack is empty.
        if not self.st2:
            # Move elements of 1st stack to 2nd stack.
            while self.st1:
                self.st2.append(self.st1.pop())
        return self.st2.pop()

    def peek(self) -> int:
        # Check if the second stack is empty.
        if not self.st2:
            # Move elements of 1st stack to 2nd stack.
            while self.st1:
                self.st2.append(self.st1.pop())
        return self.st2[-1]

    def empty(self) -> bool:
        return len(self.st1) == 0 and len(self.st2) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()