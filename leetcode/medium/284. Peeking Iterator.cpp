/**
 * problem : https://leetcode.com/problems/peeking-iterator/
 */
 
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    vector<int> arr;
    int index = 0;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        arr = vector<int>(nums.size());
        for(int i=0; i<arr.size(); i++)
            arr[i] = nums[i];
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(index >= arr.size()) return 0;
        return arr[index];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(index >= arr.size()) return 0;
	    return arr[index++];
	}
	
	bool hasNext() const {
	    return index < arr.size();
	}
};
