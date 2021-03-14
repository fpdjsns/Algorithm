/**
 * problem : https://leetcode.com/problems/binary-trees-with-factors/
 * time complexity : O(N^2)
 */

class Solution {
    int MOD = 1e9 + 7;
    unordered_map<int, int> dp;
    vector<vector<pair<int,int>>> multis;
    
    int getTreeCnt(int num) {
        if(dp.find(num) != dp.end()) return dp[num];
        int& ret = dp[num];
        ret = 1;
        
        for(pair<int,int> numPair: multis[num]) {
            long long tmp = (long long)getTreeCnt(numPair.first) * getTreeCnt(numPair.second);
            ret = (ret + tmp) % MOD;
            if(numPair.first != numPair.second) ret = (ret + tmp) % MOD;
        }
        return ret;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        multis = vector<vector<pair<int,int>>>(arr.size());
        unordered_map<int, int> numMap;
        for(int i=0; i<arr.size(); i++) numMap[arr[i]] = i;
        for(int i=0; i<arr.size(); i++) {
            for(int j=i; j<arr.size(); j++) {
                if((long long int)arr[i] * arr[j] > 1e9) continue;
                if(numMap.find(arr[i] * arr[j]) == numMap.end()) continue;
                multis[numMap[arr[i] * arr[j]]].push_back({i, j});
            }
        }
        
        int answer = 0;
        for(int i=0; i<multis.size(); i++){
            answer = (long long)(answer + getTreeCnt(i)) % MOD;
        }
        return answer;
    }
};
