/**
 * problem : https://leetcode.com/problems/merge-sorted-array/
 * time complexity : O(N + M)
 * algorithm : greedy
 */
 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = n + m -1;
        int ind1 = m-1;
        int ind2 = n-1;
        while(ind1 >= 0 && ind2 >= 0) {
            if(nums1[ind1] >= nums2[ind2]) nums1[index--] = nums1[ind1--]; 
            else nums1[index--] = nums2[ind2--];
        }
        while(ind1 >= 0) nums1[index--] = nums1[ind1--];
        while(ind2 >= 0) nums1[index--] = nums2[ind2--];
    }
};
