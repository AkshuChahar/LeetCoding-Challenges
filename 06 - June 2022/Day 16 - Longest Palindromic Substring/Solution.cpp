class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // Edge case: If the string consists of only 1 character.
        if (n == 1)
            return s;
        // Here we will treat each character of the string as middle element of a palindrome and keep track of the longest palindrome.
        // Initialise variables to keep track of the length of longest palindrome and its starting index.
        int ind = 0, len = 1;
        // Traverse the string.
        for (int i = 0; i < n; i++) {
            int start = i, end = i;
            // Move 'end' untill the a different character is encountered (Case of even-length palindromes).
            while (end + 1 < n && s[end] == s[end + 1])
                end++;
            // Check on both sides.
            while (start - 1 >= 0 && end + 1 < n && s[start - 1] == s[end + 1]) {
                start--;
                end++;
            }
            // Check if current palindrome is the longest one so far.
            int curr = end - start + 1;
            if (curr > len) {
                // Update the length and starting index.
                len = curr;
                ind = start;
            }
        }
        return s.substr(ind, len);
    }
};