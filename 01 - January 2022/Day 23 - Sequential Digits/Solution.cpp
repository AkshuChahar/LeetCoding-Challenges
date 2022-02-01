class Solution {
public:
    vector<int> ans;
    // Funtion to search for numbers.
    void dfs(int low, int high, int i, int num) {
        // If the current sequential number is in range. Add to 'ans'.
        if (num >= low && num <= high)
            ans.push_back(num);

        // If the number exceeds 'high' or 'i' has reached 10, we break the loop.
        if (num > high || i > 9)
            return;

        // We recur for next 'i' in the one's place.
        dfs(low, high, i+1, num*10+i);
    }

    vector<int> sequentialDigits(int low, int high) {
        for (int i=1; i<=9; i++)
            dfs(low, high, i, 0);

        sort(ans.begin(), ans.end());
        return ans;
    }
};