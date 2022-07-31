class NumArray {
public:
    // Initialise a vector and variable to store the array and sum.
    vector<int> arr;
    int sum = 0;

    NumArray(vector<int>& nums) {
        arr = nums;
        // Calculate the sum.
        for (int num:arr)
            sum += num;
    }

    void update(int index, int val) {
        // Subtract the original element from the sum and add the new element.
        sum += val - arr[index];
        arr[index] = val;
    }

    int sumRange(int left, int right) {
        int ans = sum;
        // Subtract all unrequired elements from the sum and return the value.
        for (int i = 0; i < left; i++)
            ans -= arr[i];
        for (int i = right + 1; i < arr.size(); i++)
            ans -= arr[i];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */