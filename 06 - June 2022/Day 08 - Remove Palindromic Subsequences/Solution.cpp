class Solution {
public:
    int removePalindromeSub(string s) {
        // The answer is 2 if the string is a palindrome and 1 otherwise.
        // This is because we can remove all the 'a's' and 'b's' in 1 step each.
        // Check if the string is a palindrome using 2-pointers approach.
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // If we find different characters, return '2'. 
            if (s[left] != s[right])
                return 2;
            left++;
            right--;
        }
        return 1;
    }
};