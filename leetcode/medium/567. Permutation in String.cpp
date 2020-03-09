/**
 * problem : https://leetcode.com/problems/permutation-in-string/
 * algorithm: two pointer
 * time complexity: O(|s1| + |s2|)
 */
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m(26, 0);
        for (int i = 0; i<s1.size(); i++) m[s1[i] - 'a']++;
        int s = 0;
        for (int e = 0; e<s2.size(); e++) {
            int lastChar = s2[e] - 'a';
            if (m[lastChar] <= 0) {
                while (s < e && s2[s] - 'a' != lastChar) {
                    m[s2[s++] - 'a']++;
                }
                s++;
                continue;
            }
            m[lastChar]--;
            if (e - s == s1.size() - 1) return true;
        }
        return false;
    }
};
