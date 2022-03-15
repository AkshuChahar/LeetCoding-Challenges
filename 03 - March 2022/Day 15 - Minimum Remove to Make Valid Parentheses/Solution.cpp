class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        // Initialise stack to store the parentheses.
        stack<int> st;
        // Traverse through the string.
        for (int i = 0; i < n; i++) {
            // If an open parentheses is encountered, push it's index into stack.
            if (s[i] == '(')
                st.push(i);
            // If a close parentheses is encountered.
            else if (s[i] == ')') {
                // If the stack is empty, mark the parentheses index invalid.
                if (st.empty())
                    s[i] = '#';
                // Else pop a parentheses' index from stack.
                else
                    st.pop();
            }
        }
        // Mark the parentheses indexes remaining in stack invalid. 
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        // Return the string without the invalid elements.
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '#')
                ans.push_back(s[i]);
        }

        return ans;
    }
};