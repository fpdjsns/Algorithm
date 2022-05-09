/**
 * problem : https://leetcode.com/problems/total-hamming-distance/
 * time complexity : O(|nums| * |nums[i]|)
 */
 
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        for(auto num : nums) st.push(num);
        
        int answer = 0;
        while(!st.empty()) {
            stack<int> newStack;
            int oneCnt = 0;
            while(!st.empty()) {
                int now = st.top();
                st.pop();
                
                oneCnt += now % 2;
                now /= 2;
                if(now > 0) newStack.push(now);
            }
            answer += oneCnt * (n - oneCnt);
            st = newStack;
        }
        
        return answer;
    }
};
