/**
 * problem : https://leetcode.com/problems/find-the-most-competitive-subsequence/
 * time complexity : O(2N)
 * data structure : stack(deque)
 * /

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> st;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (!st.empty() && st.back() > num && st.size() + (n - i) > k) {
                st.pop_back();
            } 
            
            if(st.size() < k) st.push_back(num);
        }
        
        vector<int> answer(k); 
        copy(st.cbegin(), st.cend(), answer.begin() ); 
        
        return answer;
    }
};
