/**
 * problem : https://leetcode.com/problems/search-in-rotated-sorted-array/
 * algorithm : Binary Search
 * time complexity : O(logN)
 */

class Solution {
    pair<int, int> go(int left, int right, int m, bool goRight){
        return goRight ? make_pair(m + 1, right) : make_pair(left, m-1);
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        queue<pair<int,int>> q;
        q.push({0, nums.size()-1});
        while(!q.empty()){
            int left = q.front().first;
            int right = q.front().second;
            q.pop();
            int m = (left+right)/2;
            if(nums[m] == target)
                return m;
            if(left >= right) continue;
            
            bool bigger = target > nums[m];
            bool leftAsc = nums[m] >= nums[left];
            bool rightAsc = nums[m] <= nums[right];
            
            if(leftAsc && rightAsc) q.push(go(left, right, m, bigger));
            else if(leftAsc && !rightAsc) {
                q.push(go(left, right, m, true));
                if(!bigger) q.push(go(left, right, m ,false));
            }
            else if(!leftAsc && rightAsc) {
                q.push(go(left, right, m, false));
                if(bigger) q.push(go(left, right, m, true));
            }
            else q.push(go(left, right, m, !bigger));
        }
        return -1;
    }
};
