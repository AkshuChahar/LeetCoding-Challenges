class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        # Find the index at which 'x' should be placed in the list.
        ind = bisect_left(arr, x)
        # Initialise 2 pointers at the left and right of this index.
        left, right = ind - 1, ind
        # Initialise a queue for insertion from both sides.
        ans = deque([])
        # Iterate 'k' times.
        while k:
            # Check if we can take elements from both sides.
            if left >= 0 and right < n:
                # Check for closer element.
                if abs(arr[left] - x) <= abs(arr[right] - x):
                    ans.appendleft(arr[left])
                    left -= 1
                else:
                    ans.append(arr[right])
                    right += 1
            # Check if only left side elements are available.
            elif left >= 0:
                ans.appendleft(arr[left])
                left -= 1
            elif right < n:
                ans.append(arr[right])
                right += 1
            k -= 1
        return list(ans)