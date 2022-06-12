/**
 * problem : https://leetcode.com/problems/maximum-erasure-value/
 * time complexity : subsum, two-pointer
 * algorithm : O(N)
 */
 
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int ,int> indexMap;
        int n = nums.size();
        vector<int> subSums(n+1, 0);
        for(int i=0; i<n; i++){
            subSums[i+1] = subSums[i] + nums[i];
        }
        
        int answer = 0;
        int left = 0;
        for(int right = 1; right <= n; right++){
            int num = nums[right-1];
            if(indexMap.find(num) != indexMap.end()){
                left = max(left, indexMap[num]);
            }
            indexMap[num] = right;
            answer = max(answer, subSums[right]-subSums[left]);
        }
        
        return answer;
    }
};
