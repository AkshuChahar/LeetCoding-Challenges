class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        // Sort the array.
        sort(people.begin(), people.end());
        // Initialise 2 pointers: 1 at beginning and 1 at end.
        int left = 0, right = people.size() - 1;
        // Traverse the array.
        while (left <= right) {
            // Increment the number of boats.
            ans++;
            // Check if we can pair the current lightest person with current heaviest person.
            if (people[left] + people[right] <= limit)
                left++;
            right--;
        }
        return ans;
    }
};