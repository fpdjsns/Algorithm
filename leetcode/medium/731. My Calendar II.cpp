/**
 * problem : https://leetcode.com/problems/my-calendar-ii/
 * time complexity : O(|book|)
 * algorithm : subsum
 */
 
class MyCalendarTwo {
    map<int, int> cnts;
public:
    MyCalendarTwo() {
        cnts = map<int,int>();
    }
    
    bool book(int start, int end) {
        cnts[start]++;
        cnts[end]--;
        int bookCnt = 0;
        
        // check validation
        for(auto cnt: cnts){
            bookCnt += cnt.second;
            if(bookCnt <= 2) continue;
            // impossible -> recover
            cnts[start]--;
            cnts[end]++;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
