/**
 * problem : https://leetcode.com/problems/design-hashset/
 * time complexity : O(1)
 * space complexity : O(N) // N = 1000001
 */
 
class MyHashSet {
    vector<bool> check;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        check = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        check[key] = true;
    }
    
    void remove(int key) {
        check[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return check[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
