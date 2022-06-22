class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Initialise a priority queue to keep track of largest elements and push all elements in it.
        priority_queue<int> p;
        for (int num:nums)
            p.push(num);
        // Pop 'k - 1' elements.
        while (k > 1) {
            p.pop();
            k--;
        }
        return p.top();
    }
};