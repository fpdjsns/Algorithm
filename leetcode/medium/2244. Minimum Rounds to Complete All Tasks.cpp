/**
 * problem : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
 * time complexity : O(N)
 */

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnts;
        int answer = 0;
        for(auto task: tasks) 
            cnts[task]++;
        
        for(auto cnt: cnts) {
            int now = cnt.second;
            if(now == 1) return -1;
            if(now % 3 == 0) answer += now/3;
            else answer += now/3 + 1;
        }

        return answer;
    }
};
