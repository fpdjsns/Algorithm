/**
 * problem : https://leetcode.com/problems/container-with-most-water
 * time complexity : O(N)
 * algorithm : two-pointer
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0; 
        int r = n-1;
        int answer = 0;
        
        while(l < r) {
            int area = min(height[l], height[r]) * (r - l);
            answer = max(answer, area);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return answer;
    }
};
