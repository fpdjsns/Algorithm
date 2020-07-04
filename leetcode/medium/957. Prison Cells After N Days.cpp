/**
 * problem : https://leetcode.com/problems/prison-cells-after-n-days/
 */

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int size = cells.size();
        set<vector<int>> dic;
        
        for(int i=0; i<N; i++){
            vector<int> next(cells.size());
            for(int j=1; j<size-1; j++){
                next[j] = cells[j-1] == cells[j+1];
            }
            next[0] = next[size-1] = 0;
            if(dic.find(next) != dic.end()) {
                return prisonAfterNDays(cells, N % i);
            }
            dic.insert(next);
            cells = next;
        }
        return cells;
    }
};
