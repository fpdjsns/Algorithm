/**
 * problem : https://leetcode.com/problems/plus-one/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n);
        int d = 1;
        for(int i=n-1; i>=0; i--) {
            d += digits[i];
            ans[n-i-1] = d % 10;
            d /= 10;
        }
        if(d>0) 
            ans.push_back(d);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
