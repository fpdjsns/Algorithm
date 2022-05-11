/**
 * problem : https://leetcode.com/problems/count-sorted-vowel-strings/
 * time complexity : O(N)
 * algorithm : DP
 */
 
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<5; j++) {
                for(int k=j+1; k<5; k++){
                    dp[j] += dp[k];
                }
            }
        }
        int sum = 0;
        for(auto num: dp) sum += num;
        
        return sum;
    }
};
