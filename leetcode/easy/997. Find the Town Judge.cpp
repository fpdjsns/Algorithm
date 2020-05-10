/**
 * problem : https://leetcode.com/problems/find-the-town-judge/
 * time complexity : O(N + M). // M = |trust|
 */
 
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustCnt(N+1, 0);
        for(int i=0;i<trust.size();i++){
            trustCnt[trust[i][1]]++;
            trustCnt[trust[i][0]] = -N;
        }
        for(int i=1;i<=N;i++){
            if(trustCnt[i] == N-1)
                return i;
        }
        return -1;
    }
};
