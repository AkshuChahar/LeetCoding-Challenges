class Solution {
public:
    int addDigits(int num) {
        // Using the Digital Sum concept.
        return (num == 0) ? 0 : 1 + (num - 1) % 9;
    }
};