class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ans = []
        # Initialise a dictionary to dtore thr reverse of the words.
        backward = {}
        for i, word in enumerate(words):
            backward[word[::-1]] = i
        # Traverse the array.
        for i, word in enumerate(words):
            # Edge case: Check if we have an empty string.
            if word != "" and "" in backward and word == word[::-1]:
                ans.append([i, backward[""]])
                ans.append([backward[""], i])
            # Check if the current word is present in 'backward' nad has a different index, that is, its not already a palindrome.
            if word in backward and backward[word] != i:
                ans.append([i, backward[word]])
            # Check for other cases.
            for j in range(len(word)):
                if word[j:] in backward and word[:j] == word[j-1::-1]:
                    ans.append([backward[word[j:]], i])
                if word[:j] in backward and word[j:] == word[:j-1:-1]:
                    ans.append([i, backward[word[:j]]])           
        return ans