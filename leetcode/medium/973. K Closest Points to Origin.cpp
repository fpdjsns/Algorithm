/**
 * problem : https://leetcode.com/problems/k-closest-points-to-origin/
 * time complexity : O(KlogK)
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<long long,vector<int>>> q;
        for(int i=0;i<points.size();i++) {
            q.push({-(points[i][0]*points[i][0] + points[i][1]*points[i][1]), points[i]});
        }
        vector<vector<int>> ans(K);
        for(int i=0;i<K;i++){
            ans[i] = q.top().second;
            q.pop();
        }
        return ans;
    }
};
