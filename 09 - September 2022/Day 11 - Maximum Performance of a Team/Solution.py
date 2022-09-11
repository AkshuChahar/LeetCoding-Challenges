class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10 ** 9 + 7
        ans = 0
        # Initialise variables to store the current sum of speeds and a min-heap.
        curr, heap = 0, []
        # Make a list of tuples '(efficiency, speed)' and sort in descending order of 'efficiency'.
        team = sorted(zip(efficiency, speed), reverse = True)
        # Traverse through the array.
        for e, s in team:
            # Push the 'speed' to the min-heap and update 'curr'.
            curr += s
            heapq.heappush(heap, s)
            # Check if the length of min-heap exceeds 'k'.
            if len(heap) > k:
                # Remove the minimum 'speed' and update 'curr'.
                curr -= heapq.heappop(heap)
            # Update 'ans'.
            ans = max(ans, curr * e)
        return ans % MOD