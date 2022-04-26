class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Initialise variables to store the total cost and number of edges used.
        int cost = 0, edges = 0;
        // Initialise vectors to keep track of the nodes used in 'Minimum Spanning Tree' and minimum distance between nodes.
        vector<bool> visited(n);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        // Now build minimum distance edges untill we have 'n-1' edges.
        while (edges < n) {
            int curr_min = INT_MAX, curr_node = -1;
            // Pick the least distance node which is not in MST.
            for (int node = 0; node < n; node++) {
                if (!visited[node] && curr_min > dist[node]) {
                    curr_min = dist[node];
                    curr_node = node;
                }
            }
            // Update the cost and number of edges used.
            cost += curr_min;
            edges++;
            visited[curr_node] = true;
            // Update the minimum distances of nodes from current node.
            for (int node = 0; node < n; node++) {
                int distance = abs(points[curr_node][0] - points[node][0]) + abs(points[curr_node][1] - points[node][1]);
                if (!visited[node] && distance < dist[node])
                    dist[node] = distance;
            }
        }
        return cost;
    }
};