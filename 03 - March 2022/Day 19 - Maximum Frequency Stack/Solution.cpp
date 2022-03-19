class FreqStack {
public:
    // Map to store a stack of elements with a given frequency.
    unordered_map<int, stack<int>> m1;
    // Map to keep track of elements and their frequencies.
    unordered_map<int, int> m2;
    // Variable to store the maximum frequency.
    int freq;

    FreqStack() {
        // Set maximum frequency to zero.
        freq = 0;
    }

    void push(int val) {
        // Increment the frequency of the current element.
        m2[val]++;
        // Update maximum frequency.
        freq = max(m2[val], freq);
        // Update the stack for current frequency.
        m1[m2[val]].push(val);
    }

    int pop() {
        // Get the top element with maximum frequency and remove it.
        int ans = m1[freq].top();
        m1[freq].pop();
        // Update the frequency of the popped element.
        m2[ans]--;
        // If all the elements with current maximum frequency are removed, decrement maximum frequency.
        if (m1[freq].empty())
            freq--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */