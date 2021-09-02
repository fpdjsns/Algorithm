/**
 * PROBLEM : https://leetcode.com/problems/array-nesting/
 * TIME COMPLEXITY : O(n)
 */
 
class Solution {

public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int i=0; i<n; i++) {
            int length = 0;
            int j = i;
            while(nums[j] != -1) {
                length++;
                int tmp = nums[j];
                nums[j] = -1;
                j = tmp;
            }
            answer = max(answer, length);
        }
        return answer;
    }
};
