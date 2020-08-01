/**
 * problem : https://leetcode.com/problems/task-scheduler/
 * time comlexity : O(N). N = |tasks|
 */ 
 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> countMap;
        
        int maxCounts = 0;
        for(int i=0;i<tasks.size();i++){
            countMap[tasks[i]]++;
            maxCounts = max(maxCounts, countMap[tasks[i]]);
        }
        
        int idleSum = (maxCounts - 1) * n;
        
        // set idleSum
        for(map<char, int>::iterator it = countMap.begin(); it != countMap.end(); it++){
            idleSum -= min(maxCounts - 1, it->second);
        }
        idleSum += maxCounts - 1; // add maxCounts (it will be exclude)
        
        return tasks.size() + max(0, idleSum);
    }
};
