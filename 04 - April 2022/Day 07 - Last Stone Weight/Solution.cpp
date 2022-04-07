class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Initialise a priority queue.
        priority_queue<int> pq;
        // Put all the wieghts in 'pq'.
        for (int stone:stones)
            pq.push(stone);
        // Iterate untill only 1 element remains.
        while (pq.size() > 1) {
            // Get the top 2 elements.
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            // Put their difference into 'pq' if it is not 0.
            if (stone1 - stone2 != 0)
                pq.push(stone1 - stone2);
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};