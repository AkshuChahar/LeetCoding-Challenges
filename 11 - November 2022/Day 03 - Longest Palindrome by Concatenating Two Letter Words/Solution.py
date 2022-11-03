class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ans = 0
        # Initialise a dictionary to count the frequency of each word and a flag to check if we have a central word.
        freq = Counter(words)
        center = False
        # Traverse the dictionary.
        for word, count in freq.items():
            # Check if the word is a palindrome.
            if word[0] == word[1]:
                # Update 'ans' and the flag.
                if count % 2 == 0:
                    ans += count
                else:
                    ans += count - 1
                    center = True
            elif word[0] < word[1]:
                ans += 2 * min(count, freq[word[1] + word[0]])
        if center:
            ans += 1
        return 2 * ans