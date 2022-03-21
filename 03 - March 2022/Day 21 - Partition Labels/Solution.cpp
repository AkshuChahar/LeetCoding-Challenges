class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Initialise an array to store the last occurance of each character.
        int arr[26] = {-1}, n = s.size();
        for (int i = 0; i < n; i++)
            arr[s[i] - 'a'] = i;

        // Use two pointers to mark the start and end of a partition.
        int end = 0, start = 0;
        vector<int> ans = {};
        // Traverse the string.
        for (int i = 0; i < n; i++) {
            // We update the 'end' of partition to maximum of current 'end' or last occurance of current character.
            end = max(end, arr[s[i] - 'a']);
            // If we reach the 'end' index, we push that partition length in 'ans'.
            if (i == end) {
                ans.push_back(end - start + 1);
                // Update 'start'.
                start = i + 1;
            }
        }
        return ans;
    }
};