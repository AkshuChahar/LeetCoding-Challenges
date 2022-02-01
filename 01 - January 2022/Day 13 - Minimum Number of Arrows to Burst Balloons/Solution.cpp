// Function to sort the vector on 1st column.
bool f(vector<int> &a, vector<int> &b) {
    return a[1] < b[1]; // Sorting based on second column.
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), f);  // Sort the vector.

        int arrows = 1, end = points[0][1];     // Initial number of arrows and end-point.
        for(int i = 1; i < points.size(); i++) {
            if (end < points[i][0]) {           // Add arrow if end point is less than new start.
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};// Function to sort the vector on 1st column.
bool f(vector<int> &a, vector<int> &b) {
    return a[1] < b[1]; // Sorting based on second column.
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), f);  // Sort the vector.

        int arrows = 1, end = points[0][1];     // Initial number of arrows and end-point.
        for(int i = 1; i < points.size(); i++) {
            if (end < points[i][0]) {           // Add arrow if end point is less than new start.
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};