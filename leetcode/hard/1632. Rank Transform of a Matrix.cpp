/**
 * problem : https://leetcode.com/problems/rank-transform-of-a-matrix/
 * data structure : DSU, Union-Find
 */ 
 
class Solution {
    vector<int> p;
    
    int find(int n) {
        if(p[n] == -1) return n;
        return p[n] = find(p[n]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) p[b] = a;
    }
    
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        
        map<int, vector<pair<int,int>>> cellMap; // key = matrix[x][y], value = (x, y)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cellMap[matrix[i][j]].push_back({i, j});
            }
        }
        
        
        vector<int> rowRank(n, 0);
        vector<int> colRank(m, 0);
        vector<vector<int>> answer(n, vector<int>(m));
        for(auto cells: cellMap) {
            p = vector<int>(n + m, -1); // 행, 열을 선형으로 나열. [0, n)은 행, [n, n+m)은 열.    
            
            for(auto cell: cells.second) {
                // 행, 열 union
                merge(cell.first, cell.second + n);
            }
            
            // get max rank
            unordered_map<int, int> rankMap; // key = 그룹 번호, val = 최대 랭크
            for(auto cell: cells.second) {
                int rowGroup = find(cell.first);
                int colGroup = find(cell.second + n);
                rankMap[rowGroup] = max(rankMap[rowGroup], rowRank[cell.first]);
                rankMap[colGroup] = max(rankMap[colGroup], colRank[cell.second]);
            }
            
            // update
            for(auto cell: cells.second) {
                int x = cell.first; int y = cell.second;
                int rowGroup = find(x);
                int colGroup = find(y + n);
                int rank = max(rankMap[rowGroup], rankMap[colGroup]) + 1;
                    
                rowRank[x] = rank;
                colRank[y] = rank;
                
                answer[x][y] = rank;
            }
        }
        
        return answer;
    }
};
