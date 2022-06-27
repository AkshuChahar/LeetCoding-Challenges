class Solution {
public:
    int minPartitions(string n) {
        // The answer is equal to the maximum digit in 'n'.
        int ans = 0;
        for (char c:n)
            ans = max(ans, c - '0');
        return ans;
    }
};