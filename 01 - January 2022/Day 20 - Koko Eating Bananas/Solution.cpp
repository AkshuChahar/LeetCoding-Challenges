class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initial minimum and maximum speeds.
        int low = 1, high = *max_element(piles.begin(), piles.end());

        // Edge case: When the given time is equal to number of banana piles, return 'high'.
        if (piles.size() == h)
            return high;

        // Check using binary search.
        while (low < high) {
            int mid = (low + high) / 2;
            int time = 0;

            for (int pile:piles) {
                time += pile / mid + (pile % mid != 0);
                if (time > h)
                    break;
            }

            if (time > h)
                low = mid+1;
            else
                high = mid;
        }

        return high;
    }
};