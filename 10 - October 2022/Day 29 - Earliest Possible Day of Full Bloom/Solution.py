class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        ans, res = 0, 0
        # Sort the 'growTime' list and store the indices.
        ind = sorted(range(len(plantTime)), key = lambda x: -growTime[x])
        # Traverse the indices in sorted order.
        for i in ind:
            res += plantTime[i]
            ans = max(ans, res + growTime[i])
        return ans