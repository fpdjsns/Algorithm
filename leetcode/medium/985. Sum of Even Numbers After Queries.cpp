/**
 * problem : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 * time complexity : O(|nums| + |queries|)
 */

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        int sum = 0;
        
        for(auto num: nums){
            if(num % 2 == 0) sum += num;
        }
        
        for(auto query: queries) {
            int& prev = nums[query[1]];
            int newNum = prev + query[0];
            if(prev % 2 == 0) sum -= prev;
            if(newNum % 2 == 0) sum += newNum;
            prev = newNum;
            answer.push_back(sum);
        }
        return answer;
    }
};
