/**
 * problem : https://leetcode.com/problems/path-crossing/
 * time complexity : O(N)
 */

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visits;
        pair<int, int> dot = {0, 0};
        visits.insert(dot);
        for(auto direct: path) {
            if(direct == 'N')   dot.first--;
            else if(direct == 'S')  dot.first++;
            else if(direct == 'E')  dot.second++;
            else dot.second--;
            
            if(visits.count(dot)) return true;
            visits.insert(dot);
        }
        
        return false;
    }
};
