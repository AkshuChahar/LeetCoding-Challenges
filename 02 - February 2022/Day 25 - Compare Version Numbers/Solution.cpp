class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();

        // Initialise variables to store each revision.
        int num1 = 0;
        int num2 = 0;

        // Traverse both strings.
        int i = 0;
        int j = 0;
        while (i < n1 || j < n2) {
            // Update 'num1'.
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Update 'num2'.
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare both revisions and return result accordingly.
            if (num1 > num2)
                return 1;
            if (num2 > num1)
                return -1;
            // If both are equal, check for next revision.
            num1 = num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};