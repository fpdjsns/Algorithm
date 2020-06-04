/**
 * problem : https://leetcode.com/problems/two-city-scheduling/
 * algorithm : greedy
 * time complexity : O(NlogN)
 */
 
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        sort(costs.begin(), costs.end(), [costs](vector<int>& a, vector<int>& b){
            int diffA = a[0] - a[1];
            int diffB = b[0] - b[1];
            return diffA < diffB;
        });
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += costs[i][0]; // A
            ans += costs[i+n][1]; // B
        }
        return ans;
    }
};
