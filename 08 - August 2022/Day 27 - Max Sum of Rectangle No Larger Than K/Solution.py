from sortedcontainers import SortedSet

class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        # Function to find the subarray sum that is closest to 'U' in the given 1-D array 'ps_row'.
        def maxSumSubarray(ps_row, U: int) -> int:
            # Initialise a sorted set to store the sums.
            ss, res = SortedSet([0]), -999999
            # Traverse the row.
            for c in range(n):
                diff = ps_row[c] - U
                # Check if the difference is 0.
                if diff == 0: 
                    return U
                # Perform 'Binary Search'.
                idx = ss.bisect_left(diff)
                if idx < len(ss): 
                    res = max(res, ps_row[c] - ss[idx])
                ss.add(ps_row[c])
            return res
        ans = -999999
        # Construct row-wise prefix sum matrix.
        ps = [[] for x in range(m)]
        for r in range(m):
            ps[r].append(matrix[r][0])
            for c in range(1, n):
                ps[r].append(ps[r][-1] + matrix[r][c])
        # Run over merged rows.
        for router in range(m):
            ps_row = [0 for x in range(n)]
            for rinner in range(router, m):
                ps_row = [ x + y for x, y in zip(ps_row, ps[rinner]) ]  
                ans = max(maxSumSubarray(ps_row, k), ans)
                if ans == k: 
                    return k 
        return ans