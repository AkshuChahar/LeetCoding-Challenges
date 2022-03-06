class Solution {
public:
    int countOrders(int n) {
        // We know that "Number of favourable outcomes = Probability * Total outcomes".
        // Probability = 1/2**n.
        // Total outcomes = (2n)!.
        long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= 2 * n; i++) {
            ans *= i;
            // As we have to divide the result by 2 for n-times, we perform division when 'i' is even to avoid decimals.
            if (i % 2 == 0)
                ans /= 2;
            ans %= MOD;
        }
        return ans;
    }
};