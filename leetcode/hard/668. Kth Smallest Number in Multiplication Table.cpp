/** 
 * problem : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
 * algorithm : binary search
 * time complexity : O(logMN * M)
 */
 
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m*n;
        
        int answer = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            
            // count below mid
            int cnt = 0;
            for(int i=0; i<m; i++){
                // (i + 1) * cnt = mid
                // cnt = mid / (i + 1)
                cnt += min(n, mid / (i + 1));
            }
            
            if(cnt < k) {
                left = mid+1;
            } else {
                answer = mid;
                right = mid-1;
            }
            
        }
        return answer;
    }
};
