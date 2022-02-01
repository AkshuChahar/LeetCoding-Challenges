class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = 0, middle = 0, right = 0;

        // Edge case: When leftmost seat is empty.
        for (int i=0; i<seats.size(); i++) {
            if (seats[i] == 1)
                break;
            left++;         // Here we get the distance to the leftmost OCCUPIED seat.
        }

        // For the two pointers- 'middle' and 'right', we will iterate the whole array.
        // We increment the value of 'right' for each empty seat AFTER AN OCCUPIED seat.
        // Whenever an occupied seat is encountered, 'middle' takes the max value out of current 'middle' and 'right'.
        // This way we can find out the most number of unoccupied seats between two occupied seats in the whole array.
        // 'right' is then again set to 0 for next iteration.
        for (int j=0; j<seats.size(); j++) {
            if (seats[j] == 1) {
                right++;
                middle = max(middle, right);
                right = 0;
            }
            // Edge case: When rightmost seat is empty is handled by this 'else' clause.
            else
                right++;
        }

        return max(max(left, middle/2), right);
    }
};