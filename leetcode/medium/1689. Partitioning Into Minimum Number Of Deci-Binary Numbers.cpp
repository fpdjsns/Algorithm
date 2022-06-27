/**
 * problem : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * time complexity : O(|n|)
 */
 
class Solution {
public:
    int minPartitions(string n) {
        int answer = 0;
        for(auto c: n) {
            answer = max(answer, c - '0');
        }
        return answer;
    }
};
