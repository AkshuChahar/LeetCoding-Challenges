class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Check if size of array is less than 3.
        if (arr.size() < 3)
            return false;

        int i = 1;
        // If peak is at 0, return 'false'.
        if (arr[1] <= arr[0])
            return false;
        // Move up the mountain unless peak is found.
        while (i < arr.size() && arr[i] > arr[i-1])
            i++;
        // If peak is found at the end of array, return 'false'.
        if (i == arr.size())
            return false;
        // Move down the mountain to check if there is some other peak.
        while (i < arr.size() && arr[i] < arr[i-1])
            i++;

        return i == arr.size();
    }
};