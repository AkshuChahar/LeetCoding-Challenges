class Solution:
    def frequencySort(self, s: str) -> str:
        # Count the frequency of each character and then join to form the string.
        return "".join(sorted(s, key = lambda ch, freq = Counter(s): (-freq[ch], ch)))