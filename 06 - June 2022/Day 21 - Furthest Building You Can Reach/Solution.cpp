class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // Initialise a 'Min-Heap' to keep track of the maximum height differences.
        priority_queue<int, vector<int>, greater<int>> pq;
        // Traverse through the array.
        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if (diff > 0) {
                // Insert into 'Min-Heap'.
                pq.push(diff);
                // If the size of heap exceeds the number of ladders, we make use of bricks.
                if (pq.size() > ladders) {
                    // Use bricks for the smallest distances.
                    bricks -= pq.top();
                    pq.pop();
                }
                // If we have exhausted all the bricks, we return the current building.
                if (bricks < 0)
                    return i - 1;
            }
        }
        return n - 1;
    }
};