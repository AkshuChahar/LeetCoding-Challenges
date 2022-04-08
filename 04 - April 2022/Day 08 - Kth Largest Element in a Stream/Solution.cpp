class KthLargest {
public:
    // Initialise a min-heap using priority queue.
    priority_queue<int, vector<int>, greater<int>> pq;
    int len;

    KthLargest(int k, vector<int>& nums) {
        len = k;
        // Now we add the elements to heap.
        for (int num:nums)
            add(num);
    }

    int add(int val) {
        // Enter the elements in heap if the size of heap is less than 'k'.
        if (pq.size() < len)
            pq.push(val);
        // Else check if 'val' is geater than current maximum.
        else {
            if (val > pq.top()) {
                // Pop the maximum element and add 'val' to heap.
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */