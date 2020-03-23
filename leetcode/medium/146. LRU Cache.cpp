/**
 * problem : https://leetcode.com/problems/lru-cache/
 * data structure : list, unordered_map
 */

class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> stack;
    int size = 0;
    int capacity;
    
public:
    LRUCache(int _capacity) {
        m = unordered_map<int, pair<int, list<int>::iterator>>();
        size = 0;
        capacity = _capacity;
    }
    
    int get(int key) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = m.find(key);
        if(it == m.end())
            return -1;
        
        int value = (it->second).first;
        stack.remove(key);
        m.erase(it);
        
        stack.push_back(key);
        m[key] = {value, stack.end()};
        
        return value;
    }
    
    void put(int key, int value) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = m.find(key);
        
        // already exists
        if(it != m.end()) {
            stack.remove(key);
            m.erase(it);
            size--;    
        }
        
        // put
        stack.push_back(key);
        m[key] = {value, stack.end()};
        size++;
        
        // overflow
        if(size > capacity) {
            int willDeletedKey = *(stack.begin());
            m.erase(willDeletedKey);
            stack.erase(stack.begin());
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
