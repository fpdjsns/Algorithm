/**
 * problem : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
 * time complexity : O(N)
 */
 
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        for(auto candy: candies) {
            maxCandy = max(maxCandy, candy);
        }
        
        int n = candies.size();
        vector<bool> answer(n, 0);
        for(int i=0; i<n; i++) {
            answer[i] = (candies[i] + extraCandies >= maxCandy);
        }
        return answer;
    }
};
