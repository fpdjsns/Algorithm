/**
 * problem : https://leetcode.com/problems/palindrome-partitioning/
 * time complexity : O(2^N * N)
 * algorithm : DP, backtracking
 */

class Solution {
    vector<vector<int>> dp;
    int n;
    vector<vector<string>> answer;
    
    bool isPalindrome(string& str, int s, int e) {
        if(s > e) return true;
        
        int& ret = dp[s][e];
        if(ret != -1) return ret;
        if(s == e) return ret = true;
        
        return ret = (str[s] == str[e]) && isPalindrome(str, s+1, e-1);
    }
    
    void dfs(string& str, int s, vector<int>& partitions) {
        if(s == n) {
            vector<string> tmp;
            for(int ind = 0; ind < partitions.size(); ind++) {
                int start = partitions[ind];
                int end = ind + 1 == partitions.size() ? n : partitions[ind+1];
                tmp.push_back(str.substr(start, end - start));
            }
            answer.push_back(tmp);
            return;
        }
            
        partitions.push_back(s);
        for(int e = s; e < n; e++) {
            if(!isPalindrome(str, s, e)) continue;
            dfs(str, e+1, partitions);
        }
        partitions.pop_back();
    }
    
public:
    vector<vector<string>> partition(string str) {
        n = str.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        
        vector<int> partitions;
        dfs(str, 0, partitions);
        return answer;
    }
};
