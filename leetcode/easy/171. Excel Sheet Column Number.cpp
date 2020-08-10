/**
 * problem : https://leetcode.com/problems/excel-sheet-column-number/
 * time complexity : O(N) // N = |s|
 */

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size();
        long long mul = 1;
        int ans = 0;
        for(int i=length-1; i >= 0; i--){
            ans += mul * (s[i]-'A'+1);
            mul *= 26;
        }
        return ans;
    }
};
