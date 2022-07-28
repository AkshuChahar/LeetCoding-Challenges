class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check if the strings are of different sizes.
        if (t.size() != s.size())
            return false;
        // Initialise a array to store the occurances of the characters.
        int a[26] = {0};
        for (int i = 0; i < t.size(); i++) {
            // Increment the count of character for string 't'.
            a[t[i] - 'a']++;
            // Decrement the count of character for string 's'.
            a[s[i] - 'a']--;
        }
        // Traverse the frequency array and check if any count is negative.
        for (int i = 0; i < 26; i++) {
            if (a[i] < 0)
                return false;
        }
        return true;
    }
};