class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        // Initialise a stack to store the elements.
        stack<int> s;
        // Traverse the arrays.
        int i = 0;
        for (int num:pushed) {
            // Push the element in stack.
            s.push(num);
            // Now check if the top element is needed to be popped.
            while (!s.empty() && s.top() == popped[i]) {
                // Pop the element and increment the index.
                s.pop();
                i++;
            }
        }
        // Return if all elements of 'popped' are accounted for.
        return (i == n);
    }
};