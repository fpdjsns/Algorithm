/**
 * problem : https://leetcode.com/problems/trapping-rain-water/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int trap(vector<int>& heights) {
        int length = heights.size();
        vector<int> leftMax(length), rightMax(length);
        int leftTmp = 0, rightTmp = 0;
        for(int i=0; i<length; i++){
            leftTmp = max(leftTmp, heights[i]);
            leftMax[i] = leftTmp;
            
            rightTmp = max(rightTmp, heights[length-1-i]);
            rightMax[length-1-i] = rightTmp;
        }

        int ans = 0;
        for(int i=0; i<length; i++) {
            int left = i == 0 ? 0 : leftMax[i-1];
            int right = i == length-1 ? 0 : rightMax[i+1];
            int height = heights[i];
            int sideMin = min(left, right);
            ans += max(0, (sideMin - height));
        }
        return ans;
    }
};
