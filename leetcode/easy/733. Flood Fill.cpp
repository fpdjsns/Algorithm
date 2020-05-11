/**
 * problem : https://leetcode.com/problems/flood-fill/
 * algorithm : DFS
 * time complexity : O(N^2)
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        stack<pair<int,int>> st;
        st.push({sr, sc});
        int color = image[sr][sc];
        vector<vector<bool>> check(image.size(), vector<bool>(image[0].size()));
        while(!st.empty()){
            int r = st.top().first;
            int c = st.top().second;
            st.pop();
            image[r][c] = newColor;
            check[r][c] = true;
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr < 0 || nr >= image.size()) continue;
                if(nc < 0 || nc >= image[nr].size()) continue;
                if(check[nr][nc]) continue;
                if(image[nr][nc] != color) continue;
                st.push({nr, nc});
            }
        }
        return image;
    }
};
