/**
 * problem : https://leetcode.com/problems/isomorphic-strings/
 * time complexity : O(N). N = |s| = |t|
 */
 
class Solution {
    char set(unordered_map<char, char>& dict, char c, int& ind) {
        if(dict.find(c) == dict.end()) 
            dict[c] = 'a' + (ind++);
        return dict[c];
    }
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> dictS, dictT;
        int indS = 0; int indT = 0;
        
        for(int i =0; i<s.size(); i++){
            if(set(dictS, s[i], indS) != set(dictT, t[i], indT))
                return false;
        }
        return true;
    }
};
