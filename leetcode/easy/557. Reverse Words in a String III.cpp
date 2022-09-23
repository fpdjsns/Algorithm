/**
 * problem : https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * time complexity : O(N)
 */
 
class Solution {
public:
    string reverseWords(string s) {
        int start = -1;
        for(int i=0; i<=s.size(); i++){
            if(i < s.size() && s[i] != ' ') continue;
            int len = i - start - 1;
            for(int j = 0; j < len/2; j++)
                swap(s[start + 1 + j], s[i - 1 - j]);
            start = i;
        }
        return s;
    }
};
