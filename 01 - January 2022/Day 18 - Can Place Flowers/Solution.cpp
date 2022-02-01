class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Keep track of number of flowers that can be planted.
        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++) {
            // Whenever 3 adjacent empty plots are encountered, we increment the 'count'.
            // Left and right plot are not checked for first and last plot respectively.
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                count++;
                i++;            // Skip the right plot.
            }

            // Whenever the 'count' becomes equal to 'n', we stop and return 'true'.
            if (count >= n)
                return true;
        }

        return false;
    }
};