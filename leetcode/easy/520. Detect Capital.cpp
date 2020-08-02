/**
 * problem : https://leetcode.com/problems/detect-capital/
 * time complexity : O(N)
 */
 
class Solution {
    bool isCapital(const char c) {
        return (c >= 'A' && c <= 'Z') 
;    }
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        
        if(isCapital(word[0]) && isCapital(word[1])){
            for(int i=1; i<word.size(); i++)
                if(!isCapital(word[i])) return false;
        } else {
            for(int i=1; i<word.size(); i++) {
                if(isCapital(word[i]))  return false;
            }
        }
        return true;
    }
};
