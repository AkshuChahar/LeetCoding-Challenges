class MyCircularQueue:

    def __init__(self, k: int):
        # Initialise a queue and a variable to store the maximum permissible length of the queue.
        self.q = deque()
        self.max_len = k

    def enQueue(self, value: int) -> bool:
        # Check if the queue is full.
        if len(self.q) == self.max_len:
            return False
        self.q.append(value)
        return True

    def deQueue(self) -> bool:
        # Check if the queue is empty.
        if len(self.q) == 0:
            return False
        self.q.popleft()
        return True

    def Front(self) -> int:
        # Check if the queue is empty.
        if len(self.q) == 0:
            return -1
        return self.q[0]

    def Rear(self) -> int:
        # Check if the queue is empty.
        if len(self.q) == 0:
            return -1
        return self.q[-1]

    def isEmpty(self) -> bool:
        return len(self.q) == 0

    def isFull(self) -> bool:
        return len(self.q) == self.max_len


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()