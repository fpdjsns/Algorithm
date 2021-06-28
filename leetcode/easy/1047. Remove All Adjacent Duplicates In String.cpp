/**
 * problem : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * time complexity : O(N)
 */

class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        for(auto c: s) {
            if(!answer.empty() && answer.back() == c) {
                answer.pop_back();
            } else {
                answer.push_back(c);
            }
        }
        return answer;
    }
};
