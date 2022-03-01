class Solution {
public:
    vector<int> countBits(int n) {
        // In this problem, we will be using the relationship between odd and even numbers.
        // If we have 2 numbers, x and y such that, x/2 = y.
        // Then if x is even, it will have same number of 1's as y.
        // If x is odd, it will have 1 additional 1's than y.

        vector<int> ans(n+1, 0);
        // Check for each 'i' in 'n' using the above logic.
        // 'ans[i/2]' gives the number of 1's in 'i/2' and 'i%2' tells us if the number is odd or even.
        for (int i = 0; i <= n; i++)
            ans[i] = ans[i/2] + i % 2;

        return ans;
    }
};