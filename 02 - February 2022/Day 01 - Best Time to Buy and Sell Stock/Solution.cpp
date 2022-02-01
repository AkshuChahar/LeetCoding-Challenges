class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We keep track of the profit and buying price.
        int profit = 0, buy = 0;

        for (int i=1; i<prices.size(); i++) {
            // If we encounter a price more than the buying price, we update the 'profit'.
            if (prices[buy] < prices[i])
                profit = max(profit, prices[i] - prices[buy]);
            // If we encounter a price less than buying price, we update the buying price.
            else
                buy = i;
        }
        return profit;
    }
};