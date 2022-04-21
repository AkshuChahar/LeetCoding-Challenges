class MyHashSet {
public:
    // Initialise a 2-D vector of constant number of rows.
    const int res_size = 100;
    vector<int> res[100];

    MyHashSet() {}

    void add(int key) {
        if (!contains(key)) {
            // Get the row of 'key'.
            int index = key % res_size;
            // Add 'key' in the 'index-th' row.
            res[index].push_back(key);
        }
    }

    void remove(int key) {
        // Get the row of 'key'.
        int index = key % res_size;
        // Check for 'key' in the 'index-th' row.
        for (auto it = res[index].begin(); it != res[index].end(); it++) {
            // If 'key' is encountered, erase it.
            if (*it == key) {
                res[index].erase(it);
                break;
            }
        }
    }

    bool contains(int key) {
        // Get the row of 'key'.
        int index = key % res_size;
        // Check for 'key' in the 'index-th' row.
        for (auto it = res[index].begin(); it != res[index].end(); it++) {
            // If 'key' is encountered, return 'true'.
            if (*it == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */