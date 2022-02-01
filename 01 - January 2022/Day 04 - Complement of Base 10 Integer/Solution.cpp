class Solution {
public:
    int bitwiseComplement(int n) {
        int i = 2, temp = n;

        while (temp >> 1) {
            temp >>= 1;
            i <<= 1;
        }

        return i - n - 1;
    }
};