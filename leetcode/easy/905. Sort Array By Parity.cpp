/**
 * problem : https://leetcode.com/problems/sort-array-by-parity/
 * time, space complexity : O(N)
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        vector<int> answer(n);
        for(auto num: nums) {
            if(num%2 == 0) answer[left++] = num;
            else answer[right--] = num;
        }
        return answer;
    }
};
