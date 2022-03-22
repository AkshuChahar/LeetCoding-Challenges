class Solution {
public:
    string getSmallestString(int n, int k) {
        // Create a string of size 'n' and fill it with 'a'.
        string ans(n, 'a');
        // Update 'k'.
        k -= n;

        // Traverse 'ans' from right.
        int i = n - 1;
        while (k > 0) {
            // Find the maximum character we can store at 'i'.
            int temp = min(k, 25);
            // Update the character at 'i' by 'temp'.
            ans[i] += temp;
            // Decrement 'k' by 'temp'.
            k -= temp;
            i--;
        }

        return ans;
    }
};