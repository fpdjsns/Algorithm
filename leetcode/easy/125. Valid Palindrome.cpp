/**
 * problem : https://leetcode.com/problems/valid-palindrome/
 * time complexity : O(N)
 * algorithm : tow-pointer
 */
class Solution {
    bool isAlpha(char c) {
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l <= r) {
            if(!isAlpha(s[l])) { l++; continue; }
            if(!isAlpha(s[r])) { r--; continue; }
            
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++; r--;
        }
        return true;
    }
};
