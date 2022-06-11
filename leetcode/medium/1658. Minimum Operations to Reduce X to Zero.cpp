/**
 * problem : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * time complexity : O(N)
 * algorithm : subsum, two-pointer
 */
 
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> subSums(n+1, 0);
        for(int i=1; i<=n; i++)
            subSums[i] = nums[i-1] + subSums[i-1];
      
        int mediumSums = subSums[n] - x;
        int answer = 1e9;
        int left = 0;
        for(int right=1; right<=n; right++){
            while(left < right && subSums[right] - subSums[left] > mediumSums) left++;
            if(subSums[right] - subSums[left] == mediumSums) {
                answer = min(answer, n-(right-left));
            }
        }
        return answer == 1e9 ? -1 : answer;
    }
};
