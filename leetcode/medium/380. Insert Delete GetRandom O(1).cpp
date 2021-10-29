/**
 * problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
 * time complexity : O(1) - each function
 * data structure : map
 */

class RandomizedSet {
    vector<int> nums; // chose random
    unordered_map<int, int> index; // nums index
public:
    RandomizedSet() {
        nums.clear();
        index.clear();
    }
    
    bool insert(int val) {
        if(index.find(val) != index.end()) 
            return false;
        index[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(index.find(val) == index.end()) 
            return false;
       
        int lastNum = nums[nums.size()-1];
        nums[index[val]] = lastNum;
        index[lastNum] = index[val];
        index.erase(val);
        nums.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
