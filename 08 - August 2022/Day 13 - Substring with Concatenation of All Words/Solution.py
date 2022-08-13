class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n, k, word_length = len(s), len(words), len(words[0]) 
        substring_size = word_length * k
        # Initialise a dictionary with the count of words.
        word_count = collections.Counter(words)
        # Function for 'Sliding Window'.
        def sliding_window(left):
            # Initialise a temporary dictionary to keep count of words appeared in substring.
            words_found = collections.defaultdict(int)
            words_used = 0
            # Initialise a boolean to keep track if any excess word is found in window.
            excess_word = False
            # Traverse the window.
            for right in range(left, n, word_length):
                # Move out of the loop if we have exhausted our options.
                if right + word_length > n:
                    break
                # Get the substring.
                sub = s[right : right + word_length]
                # Check if the substring is valid.
                if sub not in word_count:
                    # Reset the window.
                    words_found = collections.defaultdict(int)
                    words_used = 0
                    excess_word = False
                    left = right + word_length # Retry at the next index
                else:
                    # Move the 'left' pointer till there is an excess word.
                    while right - left == substring_size or excess_word:
                        # Move the left bound over continously
                        leftmost_word = s[left : left + word_length]
                        left += word_length
                        words_found[leftmost_word] -= 1
                        # Check if the current word is the excess word.
                        if words_found[leftmost_word] == word_count[leftmost_word]:
                            excess_word = False
                        else:
                            words_used -= 1
                    # Update the word counts.\
                    words_found[sub] += 1
                    if words_found[sub] <= word_count[sub]:
                        words_used += 1
                    else:
                        excess_word = True
                    # Update the total number of valid numbers in the substring.
                    if words_used == k and not excess_word:
                        ans.append(left)

        ans = []
        for i in range(word_length):
            sliding_window(i)
        return ans