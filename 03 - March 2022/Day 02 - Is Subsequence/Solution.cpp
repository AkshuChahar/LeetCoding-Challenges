// Normal Solution.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        // Edge case: If 't' is smaller than 's'.
        if (n < m)
            return false;
        // Use 2-pointers and check for each element.
        int i = 0, j = 0;
        while (i < m && j < n) {
            // If a character is found, increment 'i'.
            if (s[i] == t[j])
                i++;
            // Increment 'j'.
            j++;
        }
        // Return if all elements of 's' are found, or 'i' has reached the end.
        return (i == m);
    }
};


// Follow-up Solution.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        // Edge case: If 't' is smaller than 's'.
        if (n2 < n1)
            return false;

        // Here, we store the occurances of each character of 't'.
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < n2; i++)
            m[t[i]].push_back(i);

        // We use a variable to store the occurance of previous required character.
        int res = -1;
        // Iterate over 's'.
        for (char c:s) {
            // Check if the character is present in 't'.
            if (m.find(c) == m.end())
                return false;
            // If the character is present, find its position just after 'res'.
            auto ind = m.find(c)->second;
            int pos = upper_bound(ind.begin(), ind.end(), res) - ind.begin();
            // If it does not occur after 'res', return 'false'.
            if (pos == ind.size())
                return false;
            // Else, update 'res'.
            res = ind[pos];
        }
        return true;
    }
};