class Solution:
    def trap(self, height: List[int]) -> int:
        n, ans = len(height), 0
        # Initialise two pointers and variables to store the maximum heights encountered on the 'left' and 'right' side.
        left, right, left_max, right_max = 0, n - 1, 0, 0
        # Traverse the array.
        while left < right:
            # Compare the heights at the two pointers.
            if height[left] < height[right]:
                # Update 'left_max' if needed.
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    ans += left_max - height[left]
                left += 1
            else:
                # Update 'right_max' if needed.
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    ans += right_max - height[right]
                right -= 1
        return ans