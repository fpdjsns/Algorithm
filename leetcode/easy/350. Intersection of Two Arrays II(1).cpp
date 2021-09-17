/**
 * problem : https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * time complexity : O(NlogN + MlogM)
 * space complexity : O(1)
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> answer;
        int ind2 = 0;
        for(int ind1 = 0; ind1 < nums1.size(); ind1++) {
            while(ind2 < nums2.size() && nums2[ind2] < nums1[ind1]) ind2++;
            if(ind2 < nums2.size() && nums2[ind2] == nums1[ind1]) {
                answer.push_back(nums1[ind1]);
                ind2++;
            }
        }
        
        return answer;
    }
};
