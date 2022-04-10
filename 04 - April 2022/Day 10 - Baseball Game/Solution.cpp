class Solution {
public:
    int calPoints(vector<string>& ops) {
        // Initialise a stack.
        stack<int> s;
        // Iterate over 'ops'.
        for (string op:ops) {
            // Check for each case.
            if (op == "+") {
                // Get the first and second elements.
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                // Push the sum in the stack.
                s.push(a + b);
            }
            else if (op == "D")
                s.push(2 * s.top());
            else if (op == "C")
                s.pop();
            else
                s.push(stoi(op));
        }
        // Now we sum over the whole stack to get the total sum.
        int ans = 0;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};