class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        # Initialise a heap.
        heap = [-num for num in piles]
        heapq.heapify(heap)
        # Repeat for 'k' times.
        for _ in range(k):
            # Update the heap
            curr = -heapq.heappop(heap)
            remove = curr // 2
            heapq.heappush(heap, -(curr - remove))
        return -sum(heap)