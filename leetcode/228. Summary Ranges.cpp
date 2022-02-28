/**
 * problem : https://leetcode.com/problems/summary-ranges/
 * time complexity : O(N)
 */
 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<string>();
        
        int prev = nums[0];
        int start = nums[0];
        vector<string> answer;
        for(int i=1; i<=n; i++) {
            if(i== n || nums[i] != prev + 1) {
                string tmp = to_string(start);
                if(start != prev){
                    tmp += "->" + to_string(prev);
                }
                answer.push_back(tmp);
                if(i == n) break;
                start = nums[i];
            }
            if(i < n) 
                prev = nums[i];
        }
        return answer;
    }
};
