class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        // Edge case: If length of string is less than 'k'.
        if (n < k)
            return s;
        // Initialise a stack to store the characters and how many times they occur adjacently.
        stack<pair<char, int>> st;
        // Traverse the string.
        for (int i = 0; i < n; i++) {
            // If the character occurs for the first time, push it into stack.
            if (st.empty() || st.top().first != s[i])
                st.push(make_pair(s[i], 1));
            // Else increment the count.
            else {
                auto temp = st.top();
                st.pop();
                st.push(make_pair(temp.first, temp.second + 1));
            }
            // If the count equals 'k', pop the top element.
            if (st.top().second == k)
                st.pop();
        }
        // Add the elements of the stack to a string and reverse it to get the answer.
        string ans = "";
        while (!st.empty()) {
            auto temp = st.top();
            st.pop();
            // Add the elements while the count is more than 0.
            while (temp.second) {
                ans += temp.first;
                temp.second--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};