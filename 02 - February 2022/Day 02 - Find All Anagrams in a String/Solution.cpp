class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        // Edge case: When 'p' has more characters than 's',
        if (p.size() > s.size())
            return ans;

        // We create a map and store the 'p' string characters in it with their frequencies.
        unordered_map<char, int> m;
        for (auto c:p)
            m[c]++;
        // We calculate the number of distinct characters in the target string.
        int count = m.size();

        // We are using the Sliding Window approach.
        int left = 0, right = 0, len = p.size();
        while (right < s.size()) {
            // Check if the current character of 's' is a part of 'p'.
            if (m.find(s[right]) != m.end()) {
                // Subtract 1 from the frequency of current character.
                m[s[right]]--;
                // If the frequency of current element becomes 0, we decrement 'count'.
                if (m[s[right]] == 0)
                    count--;
            }
            // If the current window size is less than the length of 'p', increment right pointer.
            if (right - left + 1 < len)
                right++;
            // If the current window size equals the length of 'p', check if all elements are found. 
            else if (right - left + 1 == len) {
                // If all elements were found, append start index to 'ans'.
                if (count == 0)
                    ans.push_back(left);
                // Now while sliding the window, we check if the leftmost element is a part of target string.
                // If it is, we increment the frequency of leftmost element and also increment 'count'.
                if (m.find(s[left]) != m.end()) {
                    m[s[left]]++;
                    // If the frequency is 1, increment 'count'.
                    if (m[s[left]] == 1)
                        count++;
                }
                // We slide the window.
                left++;
                right++;
            }
        }

        return ans;
    }
};