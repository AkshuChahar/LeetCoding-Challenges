class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Initialise a dictionary to store the visited words in their characters sorted.
        d = defaultdict(list)
        # Traverse the list.
        for word in strs:
            # Sort the characters of the string and update the dictionary.
            sorted_word = ''.join(sorted(word))
            d[sorted_word].append(word)
        ans = [val for val in d.values()]
        return ans