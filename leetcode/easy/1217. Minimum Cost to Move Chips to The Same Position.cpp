/**
 * problem : https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
 * time complexity : O(N)
 */

class Solution {
public:
    int minCostToMoveChips(vector<int>& positions) {
        int odd = 0;
        int even = 0;
        for(auto position: positions) {
            if(position % 2 == 0)
                even++;
            else 
                odd++;
        }
        return min(odd, even);
    }
};
