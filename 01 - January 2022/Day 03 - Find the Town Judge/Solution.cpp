class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Initialising vectors to keep count of those who trust other people and those who are trusted by other people
        vector<int> count1(n+1, 0), count2(n+1, 0);

        for (auto i:trust) {
            count1[i[0]]++; // Increment 'count1' for those who trust other people
            count2[i[1]]++; // Increment 'count2' for those who are trusted by prople
        }

        for(int j=1; j<n+1; j++) {
            if (count1[j] == 0 && count2[j] == n-1)
                return j; // Return the judge
        }
        return -1;
    }
};