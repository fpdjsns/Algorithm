/**
 * problem : https://leetcode.com/problems/arithmetic-slices/
 * time complexity : O(N)
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        int answer = 0;
        int cnt = 1;
        int beforeDiff = 0;
        int diff = 0;
        for(int i=1; i<n; i++){
            diff = nums[i] - nums[i-1];
            if(cnt == 1 || diff == beforeDiff)    
                cnt++;
            else 
                cnt = 2;
            answer += max(0, cnt - 2);
            beforeDiff = diff;
        }
        return answer;
    }
};
