/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    // Initialise a stack to hold the integers after the list is flattened.
    stack<int> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialise a stack to store the elements of the list.
        stack<NestedInteger> s;
        // Add all the elements to the stack.
        for (auto nl:nestedList)
            s.push(nl);
        // Traverse the stack 's'.
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            // Now check if the current element is an integer and add it to stack 'st'.
            if (curr.isInteger())
                st.push(curr.getInteger());
            // Else check for nested lists.
            else {
                auto temp = curr.getList();
                // Add all the elements to the stack 's'.
                for (auto t:temp)
                    s.push(t);
            }
        }
    }

    int next() {
        // Get the top of the stack 'st'.
        int ans = st.top();
        st.pop();
        return ans;
    }

    bool hasNext() {
        // Return if stack 'st' is not empty.
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */