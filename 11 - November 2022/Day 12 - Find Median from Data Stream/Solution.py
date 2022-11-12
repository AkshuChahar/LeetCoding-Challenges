# Import 'SortedList'.
from sortedcontainers import SortedList

class MedianFinder:

    def __init__(self):
        # Store the data in a sorted list.
        self.nums = SortedList()

    def addNum(self, num: int) -> None:
        # Add 'num' to the list.
        self.nums.add(num)

    def findMedian(self) -> float:
        # Return the middle element.
        n = len(self.nums)
        return (self.nums[n//2] + self.nums[(n - 1)//2]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()