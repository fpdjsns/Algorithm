/**
 * problem : https://leetcode.com/problems/split-array-largest-sum/
 * time complexity : O(NlogM) // M = sum of nums, N = |nums|
 * algorithm : binary search
 */
 
class Solution {
    bool canAns(vector<int>& nums, int sum, int m) {
        int subSum = 0;
        int diff = 1;
        for(auto num: nums){
            if(num > sum) return false;
            if(diff > m) break;
            if(subSum + num > sum) {
                diff++;
                subSum = 0;
            }
            subSum += num;
        }
        return diff <= m;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto num: nums) sum += num;
        
        int left = 0;
        int right = sum;
        int answer = sum;
        while(left <= right) {
            int medium = (left + right) / 2;
            if(canAns(nums, medium, m)) {
                answer = medium;
                right = medium-1;
            } else {
                left = medium+1;
            }
        }
        
        return answer;
    }
};
