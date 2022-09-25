/**
 * problem : https://leetcode.com/problems/find-all-good-indices/
 * time complexity : O(N)
 */

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nonInc(n);
        vector<int> nonDec(n);
        
        for(int i=0; i<n; i++) {
            if(nums[max(0, i-1)] >= nums[i]) nonInc[i] = nonInc[max(i-1, 0)] + 1;
            else nonInc[i] = 1;
        }
        for(int i=n-1; i>=0; i--) {
            if(nums[i] <= nums[min(n-1, i+1)]) nonDec[i] = nonDec[min(n-1, i+1)] + 1;
            else nonDec[i] = 1;
        }
        
        vector<int> answer;
        for(int i=k; i<n-k; i++){
            if(nonInc[i-1] >= k && nonDec[i+1] >= k) 
                answer.push_back(i);
        }
        return answer;
    }
};
