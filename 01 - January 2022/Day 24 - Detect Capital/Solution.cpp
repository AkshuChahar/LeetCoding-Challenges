class Solution {
public:
    bool detectCapitalUse(string word) {
        // A word made of 1 or less letters is always valid.
        if (word.size() < 2)
            return true;

        // Now we have 2 cases:
        // Case 1: When both of the first letters are capital.
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i=2; i<word.size(); i++) {
                if (islower(word[i]))
                    return false;
            }
        }
        // Case 2: When either both letters are lowercase or only the first letter is capital.
        else {
            for (int i=1; i<word.size(); i++) {
                if (isupper(word[i]))
                    return false;
            }
        }

        return true;
    }
};