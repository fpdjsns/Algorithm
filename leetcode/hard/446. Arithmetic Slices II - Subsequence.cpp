/**
 * problem : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * time complexity : O(N^2)
 * algorithm : DP
 */
 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i][diff] = nums[0~i] 까지 diff 차이가 나는 subsequence들의 수.
        vector<unordered_map<long long, int>> dp(n); 
        
        int answer = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff = (long long)nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                answer += cnt;
                dp[i][diff] += cnt + 1;
            }
        }
        
        return answer;
    }
};
