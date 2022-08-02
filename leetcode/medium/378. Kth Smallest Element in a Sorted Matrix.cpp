/**
 * problem : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * time complexity : O(Nlog(N^2))
 * algorithm : binary search
 * referring : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise
 */
 
class Solution {
    int countLessThan(vector<vector<int>>& matrix, int mid) {
        int cnt = 0;
        int j = matrix.size()-1;
        for(int i=0; i<matrix.size(); i++){
            while(j >= 0 && matrix[i][j] > mid) j--;
            cnt += j+1;
        }
        // cout << mid << " " << cnt << endl;
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int answer = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            // cout << left << " " << right << " " << mid << endl;
            int cnt = countLessThan(matrix, mid);
            if(cnt >= k) {
                answer = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return answer;
    }
};
