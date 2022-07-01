/**
 * problem : https://leetcode.com/problems/maximum-units-on-a-truck/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        int answer = 0;
        for(auto boxType: boxTypes) {
            if(truckSize == 0) break;
            int cnt = min(truckSize, boxType[0]);
            answer += boxType[1] * cnt;
            truckSize -= cnt;
        }
        return answer;
    }
};
