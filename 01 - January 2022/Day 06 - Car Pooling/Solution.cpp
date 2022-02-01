/*
First we have to sort 'trips' based on the 'from' and 'to' locations.
Then, we can track the number of passengers at each location. Whenever, the number of passengers exceeds the capacity, we return 'false'.
*/

// Using Map (Maps store value in sorted order based on their keys)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m; // Intialise a map.
        // Use locations as keys and add them to the map.
        for (int i = 0; i < trips.size(); i++) {
            m[trips[i][1]] += trips[i][0]; // Increment the number of passengers for pickup.
            m[trips[i][2]] -= trips[i][0]; // Decrement the number of passengers for drop.
        }

        for (auto j = m.begin(); j != m.end(); j++) {
            capacity -= j->second; // Loop to find if the capacity ever becomes negative (that is, available seats are less than number of passengers)
            if (capacity < 0)
                return false;
        }

        return true;
    }
};

// Optimised approach using the constraint (0 <= from i < to i <= 1000)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001);
        int count = 0;

        for (int i = 0; i < trips.size(); i++) {
            v[trips[i][1]] += trips[i][0]; // Increment the number of passengers for pickup.
            v[trips[i][2]] -= trips[i][0];  // Decrement the number of passengers for drop.
        }

        for (int j = 0; j < 1001; j++) {
            count += v[j];
            if (count > capacity) // Check if number of passengers is greater than capacity.
                return false;
        }

        return true;
    }
};