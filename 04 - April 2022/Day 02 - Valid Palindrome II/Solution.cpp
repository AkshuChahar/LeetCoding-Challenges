class Solution {
public:
    bool validPalindrome(string s) {
        // Initialise two pointers.
        int left = 0, right = s.size() - 1;
        // Initialise a counter for number of mismatched characters skipping 1 from left.
        int count_l = 0;
        // Traverse the string.
        while (left < right) {
            // If we encounter mismatched characters.
            if (s[left] != s[right]) {
                // Increment 'count_l' and 'left'.
                count_l++;
                left++;
                continue;
            }
            left++;
            right--;
            // We end the loop if more than 1 mismatched characters are found.
            if (count_l > 1)
                break;
        }

        // Re-initialise pointers and repeat the process for 'right'.
        left = 0, right = s.size()-1;
        int count_r = 0;
        while (left < right) {
            // If we encounter mismatched characters.
            if (s[left] != s[right]) {
                // Increment 'count_r' and decrement 'right'.
                count_r++;
                right--;
                continue;
            }
            left++;
            right--;
            // We end the loop if more than 1 mismatched characters are found.
            if (count_r > 1)
                break;
        }

        // We return 'true' either of 'count_l' and 'count_r' is 1 or both are 0.
        if (count_l == 1 || count_r == 1 || count_l == 0 || count_r == 0)
            return true;
        return false;
    }
};