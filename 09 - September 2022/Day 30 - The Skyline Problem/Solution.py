class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans = [[0, 0]]
        # Sort the new customised buildings.
        new_buildings = sorted([(L, -H, R) for L, R, H in buildings] + [(R, 0, 0) for _, R, _ in buildings])   
        # Initialise a max heap.
        max_heap = [(0, float('inf'))]
        # Traverse the 'new_buildings'.
        for x, negative_height, R in new_buildings:
            while x >= max_heap[0][1]:
                # Reduce max height up to date, i.e. only consider max height in the right side of line x.
                heapq.heappop(max_heap)
            if negative_height:
                # Consider each height, as it may be the potential max height.
                heapq.heappush(max_heap, (negative_height, R))
            curr_max_height = -max_heap[0][0]
            # Update 'ans'.
            if ans[-1][1] != curr_max_height:
                ans.append([x, curr_max_height])
        return ans[1:]