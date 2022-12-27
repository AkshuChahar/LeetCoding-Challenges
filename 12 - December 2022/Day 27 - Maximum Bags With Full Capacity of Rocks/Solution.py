class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        ans = 0
        # Calculate the emptiness of each bag.
        empty = [total - curr for total, curr in zip(capacity, rocks)]
        empty.sort()
        # Traverse the sorted list.
        for cap in empty:
            # Check if current bag can be filled.
            if cap <= additionalRocks:
                additionalRocks -= cap
                ans += 1
            else:
                break
        return ans