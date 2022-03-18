class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        // Store the last occurances of each character in the string.
        int last[26] = {-1};
        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;

        // Initialise a stack to store the elements and a boolean array to keep track of visited characters.
        stack<char> st;
        bool visited[26] = {false};
        // Traverse the string.
        for (int i = 0; i < n; i++) {
            // If the character is already visited, we continue to next element.
            if (visited[s[i] - 'a'])
                continue;
            // Else we check for lexicographical order.
            // If the current element is smaller than the stack element, we pop those elements if they are present at later place.
            while (!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            // Add the current element to stack and mark it visited.
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        // To get the final answer, copy the stack elements in a string and reverse it.
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};