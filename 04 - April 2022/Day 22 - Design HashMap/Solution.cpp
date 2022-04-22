class MyHashMap {
public:
    // Initialise an array of the given size.
    int data[1000001];
    MyHashMap() {
        // Initialise the array with '-1' indicating it to be empty.
        fill(data, data + 1000000, -1);
    }

    void put(int key, int value) {
        // Treat the index as 'key' and the element as 'value'.
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        // Refill the given index with '-1'.
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */