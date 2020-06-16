/**
 * problem : https://leetcode.com/problems/target-sum/
 */ 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        map<int, int> before;

        if(nums.size() == 0) return 0;
        before[nums[0]]++;
        before[-nums[0]]++;
        for(int i=1;i<nums.size();i++){
            map<int, int> next;
            for(map<int,int>::iterator it = before.begin(); it != before.end(); it++){
                int num = it->first;
                next[num + nums[i]] += it->second;
                next[num - nums[i]] += it->second;
            }
            before = next;
        }
        
        return before[S];
    }
};
