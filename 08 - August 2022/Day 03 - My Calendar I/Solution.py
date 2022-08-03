class MyCalendar:

    def __init__(self):
        # Initialise the calender as a list of tupples.
        self.calender = []

    def book(self, start: int, end: int) -> bool:
        # Traverse the calender.
        for s, e in self.calender:
            # Check if the current event satisfies the conditions.
            if s < end and start < e:
                return False
        # Add the time to the list.
        self.calender.append((start, end))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)