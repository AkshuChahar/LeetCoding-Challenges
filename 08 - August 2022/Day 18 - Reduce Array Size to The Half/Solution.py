class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        n, ans = len(arr) // 2, 0
        # Store the frequency of each integer in the array.
        d = Counter(arr)
        # Sort the dictionary by the frequency of integers in descending order to get a list of sorted values.
        freq = sorted(d.values(), reverse = True)
        # Iterate while we the array at more than half its original size.
        while (n > 0):
            # Delete the most frequent element and update the size of resulting set. Here 'ans' also serves asan index.
            n -= freq[ans]
            ans += 1
        return ans