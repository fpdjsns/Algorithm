/**
 * problem : https://leetcode.com/problems/is-subsequence/
 * time complexity : O(N), N = |t|
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind = 0;
        for(int i=0; i<t.size(); i++){
            if(ind == s.size()) break;
            if(s[ind] == t[i]) ind++;
        }
        return ind == s.size();
    }
};
