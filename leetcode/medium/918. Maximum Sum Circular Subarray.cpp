/**
 * problem : https://leetcode.com/problems/maximum-sum-circular-subarray/
 * time comlexity : O(N)
 */
 
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = A[0];
        
        int maxSub = A[0];
        int minSub = A[0];
        
        int sum = 0;
        int sumMax = 0;
        int sumMin = 0;
        int maxNum = A[0];
        
        for(int i=0; i< A.size(); i++){
            sumMax = sumMax + A[i] > 0 ? sumMax + A[i] : 0;
            maxSub = max(maxSub, sumMax);
            sumMin = sumMin + A[i] < 0 ? sumMin + A[i] : 0;
            minSub = min(minSub, sumMin);
            
            sum += A[i];
            maxNum = max(maxNum, A[i]);
        }
        
        return maxNum < 0 ? maxNum : max(maxSub, sum - minSub);
    }
};
