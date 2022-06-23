class Solution {
public:
    // Function for sorting.
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        // Sort the list of courses on the basis off their end date.
        sort(courses.begin(), courses.end(), cmp);
        // Initialise a variable to store the time used.
        int time = 0;
        // Initialise a priority queue to keep track of the courses which are being taken.
        priority_queue<int> pq;
        // Traverse through the courses.
        for (auto course:courses) {
            // Add the current course duration to the queue and 'time'.
            time += course[0];
            pq.push(course[0]);
            // Check if the 'time' exceeds the end date of the course.
            if (time > course[1]) {
                // Remove the maximum duration course.
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};