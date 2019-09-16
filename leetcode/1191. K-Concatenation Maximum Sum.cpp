/*
 * 문제 : https://leetcode.com/problems/k-concatenation-maximum-sum/
 * 시간복잡도 : O(N + M) // N = arr.length, M = k
 */

class Solution {
public:
    
    int MOD = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int prefixMaxSum = 0;
        int postfixMaxSum = 0;
        int maxSum = 0;
        int totalSum = 0;
        
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            prefixMaxSum = max(prefixMaxSum, sum);
        }
        sum = max(0, sum);
        
        int tmpTotalSum = 0;
        for(int i=0;i<k;i++){
            if(i == k-2)
                tmpTotalSum = totalSum;
            totalSum = (totalSum + sum) % MOD;
        }
        
        sum = 0;
        for(int i=arr.size()-1;i>=0;i--){
            sum += arr[i];
            postfixMaxSum = max(postfixMaxSum, sum);
        }
        
        sum = 0;
        for(int j=0;j < min(2, k);j++)
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum < 0) sum = 0;
            maxSum = max(sum, maxSum);
        }
        
        
        if(k == 1) return maxSum;
        int tmp = (prefixMaxSum + postfixMaxSum) % MOD;
        return max(max(maxSum, max(totalSum, tmp)), tmp + tmpTotalSum);
    }
};
