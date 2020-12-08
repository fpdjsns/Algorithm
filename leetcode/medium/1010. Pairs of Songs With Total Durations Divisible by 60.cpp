/**
 * problem : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * time complexity : O(N)
 */
 
class Solution {
    int SIXTEEN = 60;
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        vector<int> cnts(SIXTEEN);
        int answer = 0;
        for(auto time: times) {
            answer += cnts[(SIXTEEN - time%SIXTEEN)%SIXTEEN];
            cnts[time % SIXTEEN]++;
        }
        return answer;
    }
};
