/**
 * problem : https://leetcode.com/problems/baseball-game/
 */
 
class Solution {
    int strToInt(string str) {
        int num = 0;
        bool isPositive = true;
        for(auto c: str) {
            if(c == '-') {
                isPositive = false;
                continue;
            } 
            num *= 10;
            num += (c - '0');
        }
        if(!isPositive) num *= -1;
        return num;
    }
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string op: ops) {
            if(op=="+") {
                int top = st.top();
                st.pop();
                int sum = top + st.top();
                st.push(top);
                st.push(sum);
            }else if(op == "D"){
                st.push(2 * st.top());
            }else if(op == "C"){
                st.pop();
            }else {
                st.push(strToInt(op));
            }
        }
        
        int answer = 0;
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        return answer;
    }
};
