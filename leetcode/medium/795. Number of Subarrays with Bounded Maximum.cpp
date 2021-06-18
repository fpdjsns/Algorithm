/**
 * problem : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
 * time complexity : O(N). N = |nums|
 * algorithm : two-pointer
 */

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = 0, r = -1;
        int n = nums.size();
        int answer = 0;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            if(num >= left && num <= right) // possible
                r = i;
            if(num > right) // impossible
                l = i + 1;
            if(l <= r)
                answer += r - l + 1;
        }
        return answer;
    }
};
