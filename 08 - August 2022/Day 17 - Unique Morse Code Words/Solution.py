class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        # Initialise an array with the Morse codes.
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        # Initialise a set to store all the unique morse words.
        ans = {"".join(morse[ord(ch) - ord('a')] for ch in word) for word in words}
        return len(ans)