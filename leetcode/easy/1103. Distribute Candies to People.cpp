/**
 * peoblem : https://leetcode.com/problems/distribute-candies-to-people/
 * time complexity : O(candies)
 */
 
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people);
        int ind = 0;
        while(candies > 0) {
            int candy = min(ind + 1, candies);
            answer[(ind++) % num_people] += candy;
            candies -= candy;
        }
        return answer;
    }
};
