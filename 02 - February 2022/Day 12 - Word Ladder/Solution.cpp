class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Initialise a set to store words to ease the checking process.
        unordered_set<string> s;
        for (string word:wordList)
            s.insert(word);

        // Edge case: If 'endWord' is not in the list.
        if (!s.count(endWord))
            return 0;

        int n = beginWord.size();
        
        // Now we perform a BFS to the graph.
        // We check at every iteration if by changing a alphabet of any word at the current level, we form another word in list.
        // The moment we reach the 'endWord', we return the number of steps required.
        // First we initialise a queue to store the elements at current level.
        queue<string> q;
        q.push(beginWord);
        // Initial depth of the queue is 1.
        int depth = 1;

        while (!q.empty()) {
            depth++;
            // Now we find the current size of the queue or the number of words at current level.
            int count = q.size();
            while (count--) {
                string curr = q.front();
                q.pop();
                // We change the alphabets at each index of the current word.
                for (int i = 0; i < n; i++) {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++) {
                        // If the current alphabet is same as original, we skip.
                        if (c == curr[i])
                            continue;
                        temp[i] = c;
                        // If 'endWord' is formed, return 'depth'.
                        if (temp.compare(endWord) == 0)
                            return depth;
                        // If the word is present in set, add to queue and remove from set.
                        if (s.count(temp)) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        // If 'endWord' is not formed.
        return 0;
    }
};
