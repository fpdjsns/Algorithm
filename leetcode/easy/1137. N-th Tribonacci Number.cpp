/**
 * problem : https://leetcode.com/problems/n-th-tribonacci-number/
 * time complexity : O(N)
 */

class Solution {
public:
    int tribonacci(int n) {
        long long a, b, c;
        vector<int> arr = {0, 1, 1};
        if(n < 3) return arr[n];
        int i = 3;
        for(; i<=n; i++){ 
            arr[i%3] = arr[0] + arr[1] + arr[2];
        }
        return arr[n%3];
    }
};
