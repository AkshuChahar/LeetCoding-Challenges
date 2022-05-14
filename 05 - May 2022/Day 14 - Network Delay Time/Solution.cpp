class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Initialise a variable to store the final answer.
        int ans = INT_MIN;
        // Initialise a vector to store the adjacency list and to keep track of minimum time for a node to receive the signal.
        vector<pair<int, int>> adj[n + 1];
        vector<int> r_time(n + 1, INT_MAX);
        // Initialise a 'MIN_HEAP' for 'Dijkstra's Algorithm'.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Build the adjacency list.
        for (vector<int> time:times)
            adj[time[0]].push_back(make_pair(time[2], time[1]));
        // Set the receive time for node 'k' as 0 and push it into the heap.
        r_time[k] = 0;
        pq.push(make_pair(0, k));
        // Use 'Dijkstra's Algorithm'.
        while (!pq.empty()) {
            int curr_time = pq.top().first, curr_node = pq.top().second;
            pq.pop();
            // Check for adjacent nodes.
            for (pair<int, int> neighbor:adj[curr_node]) {
                int n_time = neighbor.first, n_node = neighbor.second;
                // Check if we have the fastest time so far to reach the 'neighbor'.
                if (r_time[n_node] > curr_time + n_time) {
                    // Update 'r_time' and push it to the heap.
                    r_time[n_node] = curr_time + n_time;
                    pq.push(make_pair(curr_time + n_time, n_node));
                }
            }
        }
        // The final answer will be the maximum time in 'r_time'.
        for (int i = 1; i <= n; i++)
            ans = max(ans, r_time[i]);
        // If the final answer is 'INT_MAX', it means that some node cannot receive the signal.
        return (ans == INT_MAX) ? -1 : ans;
    }
};