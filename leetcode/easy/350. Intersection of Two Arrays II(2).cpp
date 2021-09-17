/**
 * problem : https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * time complexity : O(N + M)
 * space complexity : O(N)
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        
        vector<int> answer;
        
        for(auto num: nums1) dict[num]++;
        for(auto num: nums2) {
            if(dict[num] == 0) continue;
            dict[num]--;
            answer.push_back(num);
        }
        
        
        return answer;
    }
};
