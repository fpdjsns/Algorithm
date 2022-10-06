/**
 * problem : https://leetcode.com/problems/time-based-key-value-store/description/
 * time complexity : O(NlogM) // N = count of key, M = count of timestamp (when same key)
 * algorithm : binary search
 */

class TimeMap {
    unordered_map<string, map<int, string>> dict;
public:
    TimeMap() {
        dict.clear();
     }
    
    void set(string key, string value, int timestamp) {
        dict[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(dict.find(key) == dict.end()) return "";
        
        map<int, string>& arr = dict[key];
        auto it = arr.upper_bound(timestamp);
        if(it == arr.begin()) return "";
        return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
