class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        # Initialise a dictionary and store the frequencies of the words.
        d = defaultdict(int)
        for word in words:
            d[word] += 1
        # Sort the dictionary.
        ans = sorted(d, key = lambda x: (-d[x], x))
        return ans[:k]