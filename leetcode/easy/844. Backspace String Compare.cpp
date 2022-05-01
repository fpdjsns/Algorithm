/**
 * problem : https://leetcode.com/problems/backspace-string-compare/
 * time complexity : O(N+M) // N = |S|, M = |T|
 */
class Solution {
    string getNewStr(string s){
        string str;
        for(auto c: s) {
            if(c != '#') {
                str.push_back(c);
                continue;
            }
            if(str.empty()) continue;
            str.pop_back();
        }
        return str;
    }
public:
    bool backspaceCompare(string s, string t) {
        string newS = getNewStr(s);
        string newT = getNewStr(t);
        return newS == newT;
    }
};
