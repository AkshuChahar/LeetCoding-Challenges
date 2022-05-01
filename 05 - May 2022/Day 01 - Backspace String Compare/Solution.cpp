class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Initialise pointers at the end of the strings.
        int i = s.size() - 1, j = t.size() - 1;
        // Initialise variables to keep track of number of characters we have to skip.
        int count1 = 0, count2 = 0;
        // Traverse both strings.
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                // If we encounter '#', increment 'count1'.
                if (s[i] == '#') {
                    count1++;
                    i--;
                }
                // Skip 'count1' characters.
                else if (count1 > 0) {
                    count1--;
                    i--;
                }
                // When we have skipped 'count1' characters, break the loop.
                else
                    break;
            }
            while (j >= 0) {
                // If we encounter '#', increment 'count2'.
                if (t[j] == '#') {
                    count2++;
                    j--;
                }
                // Skip 'count2' characters.
                else if (count2 > 0) {
                    count2--;
                    j--;
                }
                // When we have skipped 'count2' characters, break the loop.
                else
                    break;
            }
            // If the current pointers point to different characters, return 'false'.
            if ((i >= 0 && j >= 0 && s[i] != t[j]) || ((i >= 0) != (j >= 0)))
                return false;
            i--;
            j--;
        }
        return true;
    }
};