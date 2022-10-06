class TimeMap:

    def __init__(self):
        # Initialise a dictionary to store the data.
        self.d = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # Check if the 'key' already exists in the dictionary.
        if not key in self.d:
            self.d[key] = []
        # Add the 'timestamp' and 'value' as list to the given 'key'.
        self.d[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        # Check if the 'key' exists in the dictionary.
        if not key in self.d:
            return ""
        # Check if the 'timestamp' is greater than any time.
        if timestamp < self.d[key][0][0]:
            return ""
        # Do a 'Binary Search' to return the desired result.
        left, right = 0, len(self.d[key])
        while left < right:
            mid = (left + right)//2
            if self.d[key][mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid
        return self.d[key][right - 1][1]

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)