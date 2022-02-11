class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: Return 'false' if 's2' is smaller than 's1'.
        if (s1.size() > s2.size())
            return false;

        // Store the occurances of each character of the strings in arrays.
        int a1[26] = {0};
        int a2[26] = {0};

        for (int i=0; i<s1.size(); i++) {
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }

        // Use 'Sliding Window' approach.
        int left = 0, right = s1.size()-1;
        // Initialise a boolean to keep track if a permutation is found.
        bool flag = false;
        while (right < s2.size()) {
            flag = true;
            for (int i=0; i<26; i++) {
                // If permutation is not found, update the boolean.
                if (a1[i] != a2[i])
                    flag = false;
            }
            // If permutation is found, return 'true'.
            if (flag == true)
                return true;
            // Update 'right' and occurances.
            right++;
            if (right < s2.size())
                a2[s2[right]-'a']++;
            a2[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};