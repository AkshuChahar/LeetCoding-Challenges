class Solution:
    def maxLength(self, arr: List[str]) -> int:
        n, ans = len(arr), 0
        # Initialise a list to store the various combinations.
        res = [""]
        # Traverse the array.
        for word in arr:
            for r in res:
                comb = r + word
                # Check if there is a duplicate element.
                if len(comb) != len(set(comb)):
                    continue
                # Update 'res' and 'ans'.
                res.append(comb)
                ans = max(ans, len(comb))
        return ans