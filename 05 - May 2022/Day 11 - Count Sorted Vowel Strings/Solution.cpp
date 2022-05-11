class Solution {
public:
    int countVowelStrings(int n) {
        // Using Math.
        return (n + 4)*(n + 3)*(n + 2)*(n + 1)/24;
    }
};