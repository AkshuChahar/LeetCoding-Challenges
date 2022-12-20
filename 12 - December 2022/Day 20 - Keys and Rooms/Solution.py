class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        # Initialise a stack and a list to keep track of visited rooms.
        s, visited = [], [False] * n
        s.append(0)
        visited[0] = True
        # Traverse the rooms.
        while s:
            room = s.pop()
            for r in rooms[room]:
                # Check if we have already visited the room.
                if not visited[r]:
                    s.append(r)
                    visited[r] = True
        # Check if we have visited all the rooms.
        for room in visited:
            if not room:
                return False
        return True