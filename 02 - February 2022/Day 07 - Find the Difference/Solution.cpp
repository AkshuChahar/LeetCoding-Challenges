class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;

        // Initialise an array and store the occurances of characters in 's' in it.
        int arr[26] = {0};
        for (auto c:s)
            arr[c - 'a']++;

        // Now traverse 't' and check for its occurance in 'arr'. 
	// Remember to decrement the occurance from the array to take care of duplicates.
        for (auto c:t) {
            arr[c - 'a']--;
            if (arr[c - 'a'] < 0) {
                ans = c;
                break;
            }
        }

        return ans;
    }
};