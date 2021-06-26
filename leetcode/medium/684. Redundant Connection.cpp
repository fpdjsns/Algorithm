/**
 * problem : https://leetcode.com/problems/redundant-connection/
 * time complexity : O(N)
 * algorithm : Union-Find
 */

class Solution {
    vector<int> parent;
    int find(int x) {
        if(parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        parent[u] = v;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent = vector<int>(n+1, -1);
        vector<int> answer;
        for(auto edge: edges){
            int u = edge[0]; int v = edge[1];
            if(!merge(u, v)) 
                answer = {u, v};
        }
        return answer;
    }
};
