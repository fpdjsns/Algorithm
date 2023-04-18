/**
 * problem : https://leetcode.com/problems/merge-strings-alternately/description/
 * time complexity : O(N + M)
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int ind1 = 0;
        int ind2 = 0;
        
        string answer(n+m, ' ');
        int ind = 0;
        while(ind1 < n || ind2 < m) {
            if(ind1 < n) answer[ind++] = word1[ind1++];
            if(ind2 < m) answer[ind++] = word2[ind2++];
        }
        return answer; 
    }
};
