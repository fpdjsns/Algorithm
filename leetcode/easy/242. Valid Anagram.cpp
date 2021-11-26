/**
 * problem : https://leetcode.com/problems/valid-anagram/
 * time complexity : O(N)
 */
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> cnts(26, 0);
        for(int i=0; i<s.size(); i++) {
            cnts[s[i] - 'a']++;
            cnts[t[i] - 'a']--;
        }
        for(auto cnt: cnts) {
            if(cnt != 0) return false;
        }
        
        return true;
    }
};
