class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        // Initialise pointers to do 'Binary Search'.
        int start = 0, end = row * col - 1, mid;

        while (start <= end) {
            mid = start + (end - start)/2;
            // Row will be 'mid / col' and column will be 'mid % col'.
            if (matrix[mid/col][mid%col] == target)
                return true;
            if (matrix[mid/col][mid%col] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }
};