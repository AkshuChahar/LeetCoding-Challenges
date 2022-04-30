class Solution {
public:
    // Function to perform BFS to find the shortest path between two nodes.
    double bfs(unordered_map<string, vector<pair<string, double>>>& adj, vector<string>& query) {
        // Initialise a queue to store the node and the solution till that node.
        queue<pair<string, double>> q;
        q.push(make_pair(query[0], 1));
        // Initialise a set to keep track of visited nodes.
        unordered_set<string> visited;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            // Mark as visited.
            visited.insert(curr.first);
            // Return if we have reached the end node.
            if (curr.first == query[1] && adj.find(curr.first) != adj.end())
                return curr.second;
            // Else travel to next nodes.
            for (auto a:adj[curr.first]) {
                if (visited.find(a.first) == visited.end())
                    q.push(make_pair(a.first, (double)a.second*curr.second));
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size(), n = queries.size();
        // Initialise a map to store the adjacency matrix along with the weight.
        unordered_map<string, vector<pair<string, double>>> adj;
        vector<double> ans(n);
        // Build the adjacency matrix.
        for (int i = 0; i < m; i++) {
            adj[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            adj[equations[i][1]].push_back(make_pair(equations[i][0], (double)1/values[i]));
        }
        // Do a BFS to find solution for each query.
        for (int i = 0; i < n; i++)
            ans[i] = bfs(adj, queries[i]);
        return ans;
    }
};