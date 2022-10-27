class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n, ans = len(img1), 0
        # Initialise a dictionary to store the count of overlapping transformations.
        d = defaultdict(int)
        # Function to filter out the non-zeo cells. 
        def non_zero_cells(img):
            res = []
            # Traverse the image.
            for x in range(n):
                for y in range(n):
                    # Check if the cell has value '1'.
                    if img[x][y] == 1:
                        res.append((x, y))
            return res
        # Extract non-zero cells from both images.
        img1_new = non_zero_cells(img1)
        img2_new = non_zero_cells(img2)
        # Traverse the images and find the transformation vectors.
        for (x_1, y_1) in img1_new:
            for (x_2, y_2) in img2_new:
                vec = (x_2 - x_1, y_2 - y_1)
                d[vec] += 1
                ans = max(ans, d[vec])
        return ans