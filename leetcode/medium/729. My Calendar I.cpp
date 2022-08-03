/**
 * problem : https://leetcode.com/problems/my-calendar-i/
 * time complexity : fun book - O(logN)
 * algorithm : binary search
 */
 
class MyCalendar {
    vector<int> schedules;
    unordered_map<int, int> ends;
public:
    MyCalendar() {
        schedules.clear();
    }
    
    bool book(int start, int end) {
        auto it = upper_bound(schedules.begin(), schedules.end(), start);
        
        // check next
        if(it != schedules.end() && end > *it)
            return false;
        
        // check before
        if(it != schedules.begin()) {
            if(ends[*(--it)] > start)
                return false;
            it++;
        }
        
        schedules.insert(it, start);
        ends[start] = end;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
