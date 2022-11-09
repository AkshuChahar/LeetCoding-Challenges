class StockSpanner:

    def __init__(self):
        # Initialise a stack to store the spans.
        self.st = []

    def next(self, price: int) -> int:
        ans = 1
        # Traverse the stack.
        while self.st and self.st[-1][0] <= price:
            # Update the stack and 'ans'.
            ans += self.st.pop()[1]
        self.st.append([price, ans])
        return ans


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)