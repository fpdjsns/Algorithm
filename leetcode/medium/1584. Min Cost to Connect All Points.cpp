/**
 * problem : https://leetcode.com/problems/min-cost-to-connect-all-points/
 * time complexity : O(NlogN) // N = |points| ^ 2
 * algorithm : Kruskal
 */

class Solution {
    int n;
    vector<int> p;
    
    int find(int n){
        if(p[n] == -1) return n;
        return p[n] = find(p[n]);
    }
    
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        p[a] = b;
        return true;
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        p = vector<int>(n, -1);
        
        vector<pair<int, pair<int,int>>> dist;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist.push_back({diff, {i, j}});
            }
        }
        
        sort(dist.begin(), dist.end());
        int answer = 0;
        for(auto value: dist) {
            int cost = value.first;
            int x = value.second.first;
            int y = value.second.second;
            
            if(merge(x, y)) answer += cost;
        }
        
        return answer;
    }
};
