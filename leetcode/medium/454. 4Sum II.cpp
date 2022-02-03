/**
 * problem : https://leetcode.com/problems/4sum-ii/
 * time complexity : O(N^2)
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> dict;
        for(auto num1: nums1) {
            for(auto num2: nums2) {
                dict[num1 + num2]++;  
            }
        }
        int answer = 0;
        for(auto num3: nums3) {
            for(auto num4: nums4) {
                int tmp = -1 * (num3 + num4);
                if(dict.find(tmp) != dict.end()){
                    answer += dict[tmp];
                }
            }
        }
        return answer;
    }
};
