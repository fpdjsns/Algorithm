/**
 * problem : https://leetcode.com/problems/check-if-it-is-a-straight-line/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        if(coordinates[1][0] == coordinates[0][0])
            return false;
        long tmp = (long)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for(int i=1;i<coordinates.size();i++){
            if((coordinates[i][0] - coordinates[i-1][0]) == 0)
                return false;
            if(tmp != (long)(coordinates[i][1] - coordinates[i-1][1]) / (coordinates[i][0] - coordinates[i-1][0]))
                return false;
        }
        return true;
    }
};
