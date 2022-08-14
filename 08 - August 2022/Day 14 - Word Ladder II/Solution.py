class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        n = len(beginWord)
        ans = set()
        # Edge case: Check if the 'endWord' is in the dictionary.
        if endWord not in wordList:
            return []
        # Initialise a dictionary to keep track of the words that can be created by changing 1 character.
        d = defaultdict(list)
        # Check if the 'beginWord' is a part of the dictionary or not.
        if beginWord not in wordList:
            for i in range(n):
                d[beginWord[:i] + "*" + beginWord[i + 1:]].append(beginWord)
        # Make the connections.
        for word in wordList:
            for i in range(n):
                d[word[:i] + "*" + word[i + 1:]].append(word)
        # Initialise sets to store the paths and the visited nodes.
        curr = set([endWord])
        visited = set(endWord)
        paths = defaultdict(list)
        # Initialise a boolean to know if we found the beginning word.
        flag = True
        while curr and flag:
            temp = set()
            for word in curr:
                # Check if we have reached the 'beginWord'.
                if word == beginWord:
                    flag = False
                    break
                # Check for next word we can move to by changing 1 character.
                for i in range(n):
                    for new_word in d[word[:i] + "*" + word[i + 1:]]:
                        if new_word not in visited:
                            temp.add(new_word)
                            paths[new_word].append(word)
            # Update the sets.
            visited.update(temp)
            curr = temp
        # Function for generating the answer format.
        def dfs(word, path):
            # Traverse through 'paths'.
            for new_word in paths[word]:
                path.append(new_word)
                # Check if we have reached the 'endWord'.
                if new_word != endWord:
                    dfs(new_word, path)
                else:
                    ans.add(tuple(path))
                path.pop()
        dfs(beginWord, [beginWord])
        return list(ans)