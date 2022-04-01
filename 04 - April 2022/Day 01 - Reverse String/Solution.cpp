class Solution {
public:
    void reverseString(vector<char>& s) {
        // Initialise two pointers - one at the start and one at the end of string.
        int low = 0, high = s.size()-1;
        // Traverse untill the pointers meet.
        while (low < high) {
            // Swap both characters.
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};