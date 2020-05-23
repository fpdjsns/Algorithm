/**
 * problem : https://leetcode.com/problems/interval-list-intersections/
 * algorithm : two pointer
 * time complexity : O(N+M)
 */
 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0;
        int b = 0;
        vector<vector<int>> ans;
        while(a < A.size()) {
            // set B index
            if(b >= B.size()) break;
            
            int x= max(A[a][0], B[b][0]);
            int y = min(A[a][1], B[b][1]);
            if(x <= y) {
                ans.push_back({x, y});
            }
            
            if(B[b][1] <= A[a][1]){
                b++;
            } else {
                a++;
            }
        }
        return ans;
    }
};
