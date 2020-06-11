/**
 * problem : https://leetcode.com/problems/sort-colors/
 * algorithm : quicksort
 * time complexity : O(N)
 * reference : https://leetcode.com/problems/sort-colors/discuss/26760/C%2B%2B-solution-in-8-lines%3A-an-instance-of-the-Dutch-national-flag-problem-by-Edsger-Dijkstra
 */
 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int h = nums.size()-1;
        while(m <= h) {
            if(nums[m] < 1) 
                swap(nums[l++], nums[m++]);
            else if(nums[m] > 1)
                swap(nums[m], nums[h--]);
            else 
                m++;
        }
    }
};
