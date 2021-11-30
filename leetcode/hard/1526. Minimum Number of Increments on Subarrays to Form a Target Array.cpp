/** 
 * problem : https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
 * time complexity : O(N)
 */
 
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int answer = 0;
        int prev = 0;
        for(auto num: target){
            answer += max(0, num - prev);
            prev = num;
        }
        
        return answer;
    }
};
