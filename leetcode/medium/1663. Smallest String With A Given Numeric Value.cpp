/**
 * problem : https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
 * time complexity : O(N)
 */
 
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        for(int i=n-1; i>=0; i--){
            ans[i] += min(k, 25);
            k = max(0, k-25);
        }
        return ans;
    }
};
