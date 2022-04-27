class Solution {
public:
    static const int n = 100001;
    // Initialise the adjacency matrix and a vector to keep track of visited nodes.
    vector<int> adj[n];
    bool visited[n];

    // Function for DFS.
    void dfs(string &s, int index, vector<char>& characters, vector<int>& pos) {
        // Add the character and index in their respective lists.
        characters.push_back(s[index]);
        pos.push_back(index);
        // Mark the node as visited.
        visited[index] = true;
        // Traverse the adjacent nodes.
        for (int a:adj[index]) {
            if (!visited[a])
                dfs(s, a, characters, pos);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // Build the adjacency matrix.
        for (auto edge:pairs) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Traverse the string.
        for (int i = 0; i < s.size(); i++) {
            // If the character has not been visited by DFS, do a DFS from it.
            if (!visited[i]) {
                // Initialise vectors to store the characters and their indices.
                vector<char> characters;
                vector<int> pos;
                // Do DFS.
                dfs(s, i, characters, pos);
                // Sort 'characters' and 'pos'.
                sort(characters.begin(), characters.end());
                sort(pos.begin(), pos.end());
                // Build the new string.
                for (int j = 0; j < characters.size(); j++)
                    s[pos[j]] = characters[j];
            }
        }
        return s;
    }
};