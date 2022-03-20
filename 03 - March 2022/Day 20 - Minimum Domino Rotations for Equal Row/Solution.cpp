class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Store the occurances of each number in arrays.
        int count_tops[7] = {0}, count_bottoms[7] = {0}, same[7] = {0};
        int n = tops.size();
        for (int i = 0; i < n; i++) {
            count_tops[tops[i]]++;
            count_bottoms[bottoms[i]]++;
            // If both arrays have same element.
            if (tops[i] == bottoms[i])
                same[tops[i]]++;
        }

        // For the required result, a element should have 'count_tops + count_bottoms - same == n'.
        for (int i = 1; i < 7; i++) {
            if (count_tops[i] + count_bottoms[i] - same[i] == n)
                return n - max(count_tops[i], count_bottoms[i]);
        }
        return -1;
    }
};