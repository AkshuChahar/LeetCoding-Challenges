class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // Initialise a variable to keep count of the total pairs and a vector to keep track of the occurances of each song
        int ans = 0;
        vector<int> occur(60, 0);

/*
There are two possibilities: 
(i) time[i] divisible by 60 
(ii) time[i] not divisible by 60

We check for these every time the loop runs.
Condition (i) : If time[i] % 60 == 0, we increment the ans by occur[0].
Condition (ii): If time[i] % 60 != 0, we increment the ans by occur[60 - temp], i.e., we look into the occur vector to look for the occurance of the value we need to make the pair divisible by 60. If we don't find the value, 0 is added to ans by default.

At last, we mark the occurance of the value in occur variable.
*/
        for(int i = 0; i < time.size(); i++) {
            int temp = time[i] % 60; // 
            if (temp == 0)
                ans += occur[0];
            else
                ans += occur[60 - temp];
            occur[temp]++;
        }

        return ans;
    }
};