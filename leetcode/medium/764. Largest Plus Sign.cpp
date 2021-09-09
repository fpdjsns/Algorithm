/**
 * problem : https://leetcode.com/problems/largest-plus-sign/
 * time/space complexity : O(N^2)
 */
 
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        set<pair<int,int>> zeros;
        for(auto mine: mines){
           zeros.insert({mine[0], mine[1]}); 
        }
        
        vector<vector<int>> row(n, vector<int>(n,0));
        vector<vector<int>> reverseRow(n, vector<int>(n,0));
        vector<vector<int>> col(n, vector<int>(n,0));
        vector<vector<int>> reverseCol(n, vector<int>(n,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(zeros.find({i,j}) == zeros.end()){
                    row[i][j] = row[max(0, i-1)][j] + 1;
                    col[i][j] = col[i][max(0, j-1)] + 1;
                } 
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(zeros.find({i,j}) == zeros.end()){
                    reverseRow[i][j] = reverseRow[min(n-1, i+1)][j] + 1;
                    reverseCol[i][j] = reverseCol[i][min(n-1, j+1)] + 1;
                }
            }
        }
        
        int answer = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                int tmp = min(row[i][j], reverseRow[i][j]);
                tmp = min(col[i][j], tmp);
                tmp = min(reverseCol[i][j], tmp);
                answer = max(tmp, answer);
            }
        }
        return answer;
    }
};
