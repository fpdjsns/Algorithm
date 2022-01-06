/**
 * problem : https://leetcode.com/problems/car-pooling/
 * time complexity : O(N), N = |to|
 * algorithm : subsum 
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 1001;
        vector<int> passengers(n, 0);
        int maxTo = 0;
        for(auto trip: trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
            maxTo = max(maxTo, trip[2]);
        }
        
        // sub sum
        for(int i=0; i<=maxTo; i++){
            if(i > 0) passengers[i] += passengers[i-1];
            if(passengers[i] > capacity) return false;
        }
        return true;
    }
};
