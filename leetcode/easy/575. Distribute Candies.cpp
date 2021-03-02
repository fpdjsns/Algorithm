/**
 * problem : https://leetcode.com/problems/distribute-candies/
 * time complexity : O(N)
 */

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for(int type: candyType) {
            types.insert(type);
        }
        
        return min(types.size(), candyType.size() / 2);
    }
};
