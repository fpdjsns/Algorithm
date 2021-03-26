/**
 * problem : https://leetcode.com/problems/advantage-shuffle/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<pair<int,int>> sortedB(n);
        for(int i=0;i<n;i++) sortedB[i] = {B[i], i};
        sort(sortedB.begin(), sortedB.end());
        sort(A.begin(), A.end());
        
        int left = 0;
        int right = n-1;
        vector<int> answer(n);
        for(int i=n-1;i>=0;i--){
            if(A[right] > sortedB[i].first) answer[sortedB[i].second] = A[right--];
            else answer[sortedB[i].second] = A[left++];
        }
        
        return answer;
    }
};
