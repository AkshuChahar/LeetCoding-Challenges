class Solution {
public:
    int scoreOfParentheses(string s) {
        // Initialise a stack to store the score with current score 0.
        stack<int> st;
        st.push(0);

        // Traverse the string.
        for (char c:s) {
            // If we encounter an open parentheses, add 0 to stack.
            if (c == '(')
                st.push(0);
            // Else, update the stack as follows.
            else {
                // Get first and second element.
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                // The new score will be 'b + 2*a'.
                st.push(b + max(2 * a, 1));
            }
        }
        return st.top();
    }
};