/**
 * problem : https://leetcode.com/problems/median-of-two-sorted-arrays/
 * time complexity : O(NlogN)
 */
 
class Solution {
    
    int cnt = 0;
    
    void setQueue(vector<int>& nums, 
                 priority_queue<int>& left,
                 priority_queue<int>& right) {
        for(int num: nums) {
            if(cnt % 2 == 0) {
                left.push(num);
            } else {
                right.push(-num);
            }
            cnt++;
            
            // set ordered
            if(!left.empty() && !right.empty()) {
                int leftTop = left.top();
                int rightTop = -right.top();
                if(leftTop > rightTop) {
                    left.pop(); right.pop();
                    left.push(rightTop); 
                    right.push(-leftTop);
                }
            }
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> left; // max
        priority_queue<int> right; // min
        
        setQueue(nums1, left, right);
        setQueue(nums2, left, right);
        
        double answer = 0;
        if(cnt % 2 == 0){
            answer = (double)(left.top() - right.top()) / 2;
        } else {
            answer = left.top();
        }
        
        return answer;
    }
};
