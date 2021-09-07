/**
 * problem : https://leetcode.com/problems/slowest-key/
 * time complexity : O(N)
 */

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char, int> cnts;
        int n = releaseTimes.size();
        int before = 0;
        char answer = 'a';
        for(int i=0; i<n; i++){
            char now = keysPressed[i];
            cnts[now] = max(cnts[now], releaseTimes[i] - before);
            before = releaseTimes[i];
            if(cnts[now] > cnts[answer] || (cnts[now] == cnts[answer] && now > answer)){
                answer = now;                
            }
        }
        
        return answer;
    }
};
