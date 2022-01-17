/**
 * problem : https://leetcode.com/problems/replace-all-digits-with-characters/
 * time complexity : O(N)
 */

class Solution {
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
public:
    string replaceDigits(string s) {
        char c;
        int x = 0;
        string answer;
        for(int i=0; i<s.size(); i++){
            if(isDigit(s[i])) {
                x = 10 * x + (s[i] - '0');
            } else {
                if(i > 0) {
                    answer.push_back(c + x);
                }
                c = s[i];
                x = 0;
                answer.push_back(c);
            }
        }
        if(isDigit(s.back())) 
            answer.push_back(c + x);
        return answer;
    }
};
