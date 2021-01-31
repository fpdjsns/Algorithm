/**
 * problem : https://leetcode.com/problems/minimize-deviation-in-array/
 * time complexity : O(N * logN * logM) // N = |nums|, M = max(nums[i])
 */
 
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int num: nums) {
            // insert max num
            if(num % 2 == 1) num *= 2;
            s.insert(num); 
        }
        
        int answer = *s.rbegin() - *s.begin();
        while(*s.rbegin() % 2 == 0) {
            int num = *s.rbegin();
            s.erase(num);
            s.insert(num/2);
            answer = min(answer, *s.rbegin() - *s.begin());
        }
        return answer;
    }
};
