class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        // Initialise a stack to keep track of valid indices with '-1' to handle edge case.
        stack<int> st;
        st.push(-1);
        // Traverse the string.
        for (int i = 0; i < n; i++) {
            // When we encounter an open parentheses, push its index in the stack.
            if (s[i] == '(')
                st.push(i);
            // When we encounter a closed parentheses, we pop the topmost element from the stack.
            else {
                st.pop();
                // If the current stack is empty, we push the current index into it.
                if (st.empty())
                    st.push(i);
                // Calculate the length of the valid substring.
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};