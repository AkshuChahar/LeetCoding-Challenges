class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Main function where we initialise the 'ans' vector (final answer), 'temp' vector (keeps track of each partition) and 'left' pointer.
        vector<vector<string>> ans;
        vector<string> temp;
        int left = 0;

        // Calling the recursive 'search' function to search for palindromes in each partition.
        search(s, 0, temp, ans);

        return ans;
    }

    void search(string &s, int left, vector<string> &temp, vector<vector<string>> &ans) {
        // Applying 'Depth First Search' with 'Backtracking'.
        if (left >= s.size()) // When the 'left' pointer has reached the end of string marking the end of our solution.
            ans.push_back(temp);

        for (int right = left; right < s.size(); right++) {
            if (check(s, left, right)) { // Calling the helper function to check whether the sub-string is a palindrome or not.
                temp.push_back(s.substr(left, right - left + 1));
                search(s, right + 1, temp, ans); // Search all substrings from left = right + 1. (Backtracking)
                temp.pop_back(); // Remove the current substring from the list.
            }
        }
    }

    bool check(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--])
                return false;
        }
        return true;
    }
};