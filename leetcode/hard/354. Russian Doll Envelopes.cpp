/**
 * problem : https://leetcode.com/problems/russian-doll-envelopes/
 * time complexity : O(NlogN)
 * algorithm : DP (LIS)
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort by width. asc
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int answer = 0;
        vector<int> dp;
        // LIS
        for(auto envelope: envelopes) {
            int height = envelope[1];
            
            auto it = lower_bound(dp.begin(),dp.end(),height);
            if(it == dp.end()) dp.push_back(height);
            else *it = height;
        }
        return dp.size();
    }
};
