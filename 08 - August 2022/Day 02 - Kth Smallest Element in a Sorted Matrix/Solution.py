class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low, high, n = matrix[0][0], matrix[-1][-1], len(matrix)
        # Helper function to get the count of numbers smaller than a given number.
        def helper(num):
            count = 0
            # Traverse the matrix.
            for i in range(n):
                # Increment the count of smaller numbers.
                count += bisect_right(matrix[i], num)
            return count
        # Perform 'Binary Search'.
        while low < high:
            mid = (low + high)//2
            if helper(mid) < k:
                low = mid + 1
            else:
                high = mid
        return low