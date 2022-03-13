class Solution {
public:
    bool isValid(string s) {
        // Initialise a stack.
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            // If any open type parentheses is encountered, push it in the stack.
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            // If the stack is not empty and a close type parentheses is ecountered, check if it is the same type as the top element of stack.
            // If it is of same type, delete the top element of stack.
            else if (!st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();
                // If it is not of the same type, return 'false'.
                else
                    return false;
            }
            // If stack is empty and a close type parentheses is encountered, return 'false'.
            else
                return false;
        }
        // At the end, if we have an empty stack, we return 'true'.
        return st.empty();
    };
};