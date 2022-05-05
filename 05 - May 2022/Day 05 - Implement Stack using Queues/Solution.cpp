class MyStack {
public:
    // Initialise a queue.
    queue<int> q;

    MyStack() {}

    void push(int x) {
        // Push 'x' into queue.
        q.push(x);
        // Now reverse the queue.
        for (int i = 0; i < q.size() - 1; i++)
            q.push(pop());
    }

    int pop() {
        // Return and delete the element at front.
        int ans = top();
        q.pop();
        return ans;
    }

    int top() {
        // Return the element at the front.
        return q.front();
    }

    bool empty() {
        // Return whether the queue is empty.
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */