/**
 * problem : https://leetcode.com/problems/backspace-string-compare/
 * time complexity : O(N+M) // N = |S|, M = |T|
 * data structure : stack
 */

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> sSt;
        stack<char> tSt;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '#') {
                if (!sSt.empty()) sSt.pop();
            }
            else
                sSt.push(S[i]);
        }
        for (int i = 0; i < T.size(); i++) {
            if (T[i] == '#'){
                if(!tSt.empty()) tSt.pop();
            }
            else
                tSt.push(T[i]);
        }

        while (!sSt.empty() && !tSt.empty()) {
            if (sSt.top() != tSt.top())
                return false;
            sSt.pop(); tSt.pop();
        }
        return sSt.empty() && tSt.empty();
    }
};
