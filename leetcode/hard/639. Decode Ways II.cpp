/**
 * problem : https://leetcode.com/problems/decode-ways-ii/
 * time/space complexity: O(N) // N = |s|
 * algorithm : backtracking, DP
 */
 
class Solution {
    vector<int> dp;
    const int MAX_TENS = 26;
    const int MOD = 1e9 + 7;
    
    int toInt(char c) {
        if(c == '*') return -1;
        return c - '0';
    }
    
    int tensCnt(string& s, int ind) {
        if(ind+1 >= s.size()) return 0;
        
        int first = toInt(s[ind]);
        int second = toInt(s[ind+1]);
        
        if(first == -1 && second == -1) { // * *
            // 11, 12, 13, 14, 15, 16, 17, 18, 19,
            // 21, 22, 23, 24, 25, 26
            return 15;
        } else if(first == -1){ // * X
            if(second == 0) return 2; // 10, 20
            else if(second > 6) return 1; // 1X
            else return 2; // 1X, 2X
        } else if(second == -1){ // X *
            if(first == 1) return 9;
            else if(first == 2) return 6;
            else return 0;
        } else { // X X
            int num = first * 10 + second;
            return first != 0 && num <= MAX_TENS;    
        }
    }
    
    int backtracking(string& s, int ind) {
        if(ind >= s.size()) return 1;
        int& ret = dp[ind];
        if(ret != -1) return ret;
        
        ret = ((long long)tensCnt(s, ind) * backtracking(s, ind+2)) % MOD;
        char now = s[ind];
        if(now == '*'){
            ret = (ret + (long long)9 * backtracking(s, ind+1)) % MOD;
        } else if(s[ind] != '0'){
            if(ind + 1 < s.size()) 
                ret = (ret + backtracking(s, ind+1)) % MOD;
            else 
                ret = (ret + 1) % MOD;
        }
        
        return ret;
    }
public:
    int numDecodings(string s) {
        dp = vector<int>(s.size(), -1);
        return backtracking(s, 0);
    }
};
