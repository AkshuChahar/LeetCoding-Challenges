/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Edge case: If the graph is empty.
        if (!node)
            return NULL;

        // Intialise a map to store the nodes so we can avoid copies.
        unordered_map<Node*, Node*> m;
        // Create a new root node and add it to map.
        Node* ans = new Node(node->val, {});
        m[node] = ans;
        // Initialise a queue for BFS.
        queue<Node*> q;
        q.push(node);

        // Do a BFS.
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            // Check if the neighbours of the current node are in map.
            for (Node* neighbor:curr->neighbors) {
                // If they are not, add them to map and queue.
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                // Also add the neighbor of each of current node copy.
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        return ans;
    }
};