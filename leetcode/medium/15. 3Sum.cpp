/**
 * problem: https://leetcode.com/problems/3sum/
 * time complexity : O(N^2)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<size-2; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j= i+1; 
            int k= size-1;
            while(j < k){
                int nowSum = nums[i] + nums[j] + nums[k];
                if(nowSum == 0){
                    vector<int> now(3);
                    now[0] = nums[i]; now[1] = nums[j++]; now[2] = nums[k--];
                    ans.push_back(now);
                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(k > j && nums[k+1] == nums[k]) k--;
                } else if(nowSum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
