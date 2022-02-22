class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, n = columnTitle.size();

        // Traverse the string and update the result by multiplying it by 26 and adding the current string.
        for (int i = 0; i < n; i++)
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        return ans;
    }
};