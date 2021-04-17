/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/76502
 * time complexity : O(N^2). N = |s| 
 * data structure : stack
 */

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(stack<char>& st, char diff_char) {
    if(st.empty() || st.top() != diff_char) return false;
    st.pop();
    return true;
}

bool check(string s) {
    stack<char> st;
    for(char c: s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            bool result;
            if(c == ')') result = check(st, '(');
            if(c == ']') result = check(st, '[');
            if(c == '}') result = check(st, '{');
            
            if(!result) return false;
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    while(n--){
        if(check(s)) answer++;
        s = s.back() + s;
        s.pop_back();
    }
    return answer;
}
