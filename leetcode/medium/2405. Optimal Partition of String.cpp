/**
 * problem : https://leetcode.com/problems/optimal-partition-of-string/description/
 * time complexity : O(N)
 * algorithm : greedy
 */

class Solution {
public:
    int partitionString(string s) {
        vector<bool> exist(26, false);
        int n = s.size();
        int answer = 1;
        for(int i=0; i<n; i++){
            char c = s[i];
            if(exist[c-'a']) {
                answer++;
                exist = vector<bool>(26, false);
            }
            exist[c-'a'] = true;
        }
        return answer;
    }
};
