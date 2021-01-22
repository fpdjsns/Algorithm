/**
 * problem : https://leetcode.com/problems/regular-expression-matching/
 * time complexity : O(N^2). let, N = |s|
 * algorithm : DP, backtracking
 */

class Solution {
    vector<vector<int>> dp;
    
    bool isEqual(char s, char p){
        if(p == '.')
            return true;
        return s == p;
    }
    
    bool isMatch(string& s, string& p, int sInd, int pInd) {
        if(sInd >= s.size()) {
            bool ans = true;
            for(int i=pInd; i<p.size(); i++){
                if(i+1 < p.size() && p[i+1] == '*') {
                    i++;
                    continue;
                }
                ans = false; break;
            }
            return ans;
        }
        if(pInd >= p.size()) {
            return false;
        }
        
        int& ret = dp[sInd][pInd];
        if(ret != -1) return ret;
        ret = false;
        
        if(pInd + 1 < p.size() && p[pInd+1] == '*') {
            ret = isMatch(s, p, sInd, pInd+2);
            for(int i=sInd; i<=s.size();i++){
                if(!isEqual(s[i], p[pInd])) break;
                ret |= isMatch(s, p, i+1, pInd+2);
            }
        } else if (p[pInd] == '.') {
            ret = isMatch(s, p, sInd+1, pInd+1);
        } else {
            if(s[sInd] != p[pInd]) ret = false;
            else ret = isMatch(s, p, sInd+1, pInd+1);
        }
            
        return ret;
    }
public:
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));
        bool answer = isMatch(s, p, 0, 0);
        return answer;
    }
};
