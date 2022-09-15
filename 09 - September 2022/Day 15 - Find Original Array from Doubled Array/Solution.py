class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        n = len(changed)
        ans = []
        # Edge case: Check if the array has odd number of elements.
        if n % 2 != 0:
            return ans
        # Count the frequency of the elements and sort the list.
        freq = Counter(changed)
        changed.sort()
        # Traverse the array.
        for num in changed:
            # Check if the frequency of the curremt element is greater than 0.
            if freq[num] > 0:
                # Edge case: Check if the current element is 0.
                if (num == 0) and (freq[num] < 2):
                    return []
                num_double = num * 2
                # Check if the frequency of the doubled element is greater than 0.
                if (num_double not in freq) or (freq[num_double] == 0):
                    return []
                # Update the 'freq' and 'ans'.
                freq[num] -= 1
                freq[num_double] -= 1
                ans.append(num)
        return ans