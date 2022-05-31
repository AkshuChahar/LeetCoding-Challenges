class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        // The required number of codes is '2**k'.
        int req = 1 << k;
        // Initialise a set to store the distinct codes.
        set<string> st;
        // Check for every 'k-sized' substring of the string.
        for (int i = 0; i < n - k + 1; i++) {
            string temp = s.substr(i, k);
            // If the substring is not in the set, add it to the set.
            if (st.count(temp) == 0) {
                st.insert(temp);
                req--;
                // If all possible codes are found, return 'true'.
                if (req == 0)
                    return true;
            }
        }
        return false;
    }
};