class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        ans, prev, tank = 0, 0, startFuel
        # Initialise a max heap to keep track of the largest station we can refuel at.
        pq = []
        # Add the destination to the array.
        stations.append((target, float('inf')))
        # Traverse the array.
        for pos, fuel in stations:
            # Calculate the current fuel left in the tank.
            tank -= pos - prev
            # Check if the tank is empty.
            while pq and tank < 0:
                # Refuel from the largest station.
                tank += -heapq.heappop(pq)
                ans += 1
            # Check if the tank is still empty.
            if tank < 0:
                return -1
            # Add the current station to heap and update 'prev'.
            heapq.heappush(pq, -fuel)
            prev = pos
        return ans