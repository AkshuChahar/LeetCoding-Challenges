from sortedcontainers import SortedDict
class MyCalendarThree:

    def __init__(self):
        # Initialise a sorted dictionary to store the differential array.
        self.diff = SortedDict()

    def book(self, start: int, end: int) -> int:
        # Update the array.
        self.diff[start] = self.diff.get(start, 0) + 1
        self.diff[end] = self.diff.get(end, 0) - 1
        curr = ans = 0
        # Traverse the dictionary to get the maximum bookings.
        for i in self.diff.values():
            curr += i
            ans = max(curr, ans)
        return ans


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)