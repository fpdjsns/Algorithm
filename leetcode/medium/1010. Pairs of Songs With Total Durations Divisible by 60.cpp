/**
 * problem : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        map<int, int> cnt;
        int answer = 0;
        for(auto time: times) {
            answer += cnt[(60 - time%60)%60];
            cnt[time % 60]++;
        }
        return answer;
    }
};
