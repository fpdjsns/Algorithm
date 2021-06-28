/**
 * problem : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * time complexity : O(N)
 */

class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        for(auto c: s) {
            answer.push_back(c);
            while(answer.size() >= 2 && answer[answer.size()-1] == answer[answer.size()-2]) {
                answer.pop_back(); answer.pop_back();
            }
        }
        return answer;
    }
};
