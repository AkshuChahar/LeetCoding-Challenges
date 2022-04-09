class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // Edge case: If 'k' is equal to size of 'nums'.
        if (k == n)
            return nums;

        // Initialise a map and store the frequency of each element.
        unordered_map<int, int> m;
        for (int num:nums)
            m[num]++;
        // Initialise a priority queue.
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        // Traverse the map.
        for (auto it = m.begin(); it != m.end(); it++) {
            // Push the element in the queue in the form (frequency, element).
            pq.push(make_pair(it->second, it->first));
            // Check if the size of priority queue is greater than 'n-k'.
            if (pq.size() > (int)m.size() - k) {
                // Push the top element in 'ans'.
                ans.push_back(pq.top().second);
                // Pop the element from queue.
                pq.pop();
            }
        }
        return ans;
    }
};