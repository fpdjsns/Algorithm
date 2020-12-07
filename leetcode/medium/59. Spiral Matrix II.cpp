/** 
 * problem : https://leetcode.com/problems/spiral-matrix-ii/
 * time complexity : O(N^2)
 */

class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> generateMatrix(int n) {
        int direction = 0;
        int x=-dx[0];
        int y=-dy[0];
        vector<vector<int>> answer(n, vector<int>(n, 0));
        
        int cnt = 1;
        while(cnt <= n*n){
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            
            if(nx < 0 || nx >=n || ny < 0 || ny >= n ||
              answer[nx][ny] != 0)
                direction = (direction + 1) % 4;
            else {
                answer[nx][ny] = cnt++;
                x = nx; y = ny;
            }
        }
        
        return answer;
    }
};
