/**
 * problem : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * time/space complexity : O(N)
 */
 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visits(n, false);
        for(int i=0; i<n; i++){
            visits[nums[i]-1] = true;
        }
        vector<int> answer;
        for(int i=0; i<n; i++){
            if(visits[i]) continue;
            answer.push_back(i+1);
        }
        return answer;
    }
};
