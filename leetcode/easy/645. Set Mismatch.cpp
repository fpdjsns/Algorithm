/**
 * problem : https://leetcode.com/problems/set-mismatch/
 * time complexity : O(N)
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> visits(nums.size(), 0);
        for(int num: nums) {
            visits[num-1]++;
        }
        vector<int> answer;
        for(int i=0; i<visits.size(); i++) {
            if(visits[i]>1) answer.push_back(i+1);
        }
        for(int i=0; i<visits.size(); i++) {
            if(visits[i]==0) answer.push_back(i+1);
        }
         
        return answer;
    }
};
