class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)     // Return 0 for length is 1.
            return 0;

        // Map to store the elements as keys and index as values.
        unordered_map<int, vector<int>> m; 
        for (int i = 0; i < n; i++)
            m[arr[i]].push_back(i);

        // Queue to store the possible positions in each step.
        queue<int> q;
        q.push(0);      // Initially, we are at 0.
        int step = 0;   // Initially, the number of steps are 0.

        while (!q.empty()) {
            step++;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                int curr = q.front();
                q.pop();

                // For jumping 1 step back.
                if (curr > 0 && m.find(arr[curr-1]) != m.end())
                    q.push(curr - 1);

                // For jumping 1 step forward.
                if (curr < n-1 && m.find(arr[curr+1]) != m.end()) {
                    // Return 'step' if the next value is the end of array.
                    if (curr == n-2)
                        return step;
                    q.push(curr+1);
                }

                // For jumping to equal values.
                if (m.find(arr[curr]) != m.end()) {
                    // Visit each element for the current key.
                    for (auto j:m[arr[curr]]) {
                        if (j != curr) {  // Avoiding the current position.
                            if (j == n-1) // If we reach end, return 'end'.
                                return step;
                            q.push(j);
                        }
                    }
                }

                // Erase the key from map to avoid repeatition.
                m.erase(arr[curr]);
            }
        }
        return step;
    }
};