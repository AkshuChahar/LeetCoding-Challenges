class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        # Calculate the area of both rectangles.
        a1 = (ay2 - ay1) * (ax2 - ax1)
        a2 = (by2 - by1) * (bx2 - bx1)
        # Calculate the overlap for x and y axis.
        left, right = max(ax1, bx1), min(ax2, bx2)
        x = right - left
        top, bottom = min(ay2, by2), max(ay1, by1)
        y = top - bottom
        # Calculate the overlaping area.
        o = 0
        if x > 0 and y > 0:
            o = x * y
        return a1 + a2 - o