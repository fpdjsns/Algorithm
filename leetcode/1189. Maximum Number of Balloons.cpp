/*
 * 문제 : https://leetcode.com/problems/maximum-number-of-balloons/
 * 시간복잡도 : O(N) // N = |text|
 */
 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> alpha(26, 0);
        for(int i=0;i<text.size();i++){
            alpha[text[i]-'a']++;
        }
        
        int ans = 1e9;
        ans = min(ans, alpha['a'-'a']); // a - 1
        ans = min(ans, alpha['b'-'a']); // b - 1
        ans = min(ans, alpha[('l'-'a')]/2); // l - 2
        ans = min(ans, alpha['n'-'a']); // n - 1
        ans = min(ans, alpha[('o'-'a')]/2); // o - 2
        
        return ans;
    }
};
