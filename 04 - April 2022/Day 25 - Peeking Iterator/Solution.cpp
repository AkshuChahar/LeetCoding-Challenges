/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *         Data* data;
 *  public:
 *        Iterator(const vector<int>& nums);
 *         Iterator(const Iterator& iter);
 *
 *         // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */

class PeekingIterator : public Iterator {
public:
    // Initialise a new variable to store the next value.
    int nextVal;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

        // Store the next value in 'nextVal'.
        nextVal = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        // Simply return the next value.
        return nextVal;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        // Here we return the current next value and move the next iterator forward.
        // Store the next value in temporary variable.
        int temp = nextVal;
        // Check if there is a next value in the vector.
        if (Iterator::hasNext())
            nextVal = Iterator::next();
        else
            nextVal = NULL;
        return temp;
    }

    bool hasNext() const {
        return nextVal;
    }
};