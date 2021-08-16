/**
 * problem : https://leetcode.com/problems/longest-common-prefix/
 * time complexity : O(NM) . N = |strs|, M = |strs[i]|
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        for(auto str: strs) {
            int i = 0;
            for(i=0; i < min(answer.size(), str.size()); i++){
                if(answer[i] != str[i]) break;
            }
            answer = answer.substr(0, i);
        }
        return answer;
    }
};
