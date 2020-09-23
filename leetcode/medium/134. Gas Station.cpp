/**
 * problem : https://leetcode.com/problems/gas-station/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0;
        int nowGas = 0;
        int answer = 0;
        for(int i=0; i<gas.size(); i++){
            nowGas += gas[i] - cost[i];
            sumGas += gas[i] - cost[i];
            if(nowGas >= 0) continue;
            
            // impossible -> start next station
            answer = i+1;
            nowGas = 0;
            
        }
        return sumGas >= 0 ? answer : -1;
    }
};
