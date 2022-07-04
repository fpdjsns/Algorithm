/**
 * problem : https://leetcode.com/problems/candy/
 * time complexity : O(N)
 * algorithm : greedy
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i=1; i<n; i++) {
            if(ratings[i] <= ratings[i-1]) continue;
            left[i] = left[i-1] + 1;
        }
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] <= ratings[i+1]) continue;
            right[i] = right[i+1] + 1;
        }
        
        int answer = 0;
        for(int i=0; i<n; i++) 
            answer += max(left[i], right[i]);
        return answer;
    }
};
