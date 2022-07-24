/**
 * problem : https://leetcode.com/problems/first-letter-to-appear-twice/
 * time complexity : O(N)
 * data structure : set
 */

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> dict;
        for(auto c: s) {
            if(dict.find(c) != dict.end())
                return c;
            dict.insert(c);
        }
        return ' ';
    }
};
