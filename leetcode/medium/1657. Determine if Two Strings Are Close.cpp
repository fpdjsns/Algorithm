/**
 * problem : https://leetcode.com/problems/determine-if-two-strings-are-close/
 * time complexity : O(N + M)
 */

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1, s2;
        vector<int> cnt1(26), cnt2(26);
        for(auto word: word1) {
            s1.insert(word);
            cnt1[word-'a']++;
        }
        for(auto word: word2) {
            s2.insert(word);
            cnt2[word-'a']++;
        }
        
        if(s1 != s2) return false;
        // O(26 * log(26))
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};
