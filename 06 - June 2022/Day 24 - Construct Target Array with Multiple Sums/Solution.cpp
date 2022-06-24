class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Initialise priority queue for storing all the elements in 'target' in decreasing order.
        priority_queue<int> pq;
        // Get the sum of elements in 'target'.
        long long sum = 0;
        for (auto num : target) {
            pq.push(num);
            sum+=num;
        }
        // Iterate untill all elements in queue becomes 1.
        while (pq.top() != 1) {
            // Remove the greatest element as it was last upadted when converting array to target. So we are left with sum of other elements.
            sum -= pq.top();
            // When there are elements greeter than 1 then sum of other elements can not be 0 or sum can not be greater than top element because sum + x is pq.top().
            if (sum == 0 || sum >= pq.top())
                return false;
            // If we delete all copies of sum from pq.top() we get an old element.
            int old = pq.top() % sum;
            // All old elements were > 0 so it can not be 0 unless sum is 1 (This is only possible if array has only 2 elements).
            if (sum != 1 && old == 0)
                return false;
            // Delelte the greatest elemtnt and add old element to restore array.
            pq.pop();
            pq.push(old); 
            sum += old;
        }
        return true;
    }
};