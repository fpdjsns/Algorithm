
/**
 * problem : https://leetcode.com/problems/min-stack/
 * data structure : stack
 */
 
class MinStack {
    stack<int> st;
    stack<int> minSt;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        st = stack<int>();
        minSt = stack<int>();
    }
    
    void push(int x) {
        if(minSt.empty() || minSt.top() >= x) minSt.push(x);
        st.push(x);
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
