/**
 * problem : https://leetcode.com/problems/number-of-good-paths/
 * time complexity : O(NlogN)
 * algrithm : Union-Find
 */
 
class Solution {
    vector<int> p;
    int find(int n) {
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        p = vector<int>(n, -1);
        
        // set
        vector<unordered_set<int>> adj(n);
        for(auto edge: edges) 
            adj[min(edge[0], edge[1])].insert(max(edge[0], edge[1]));

        vector<pair<int,int>> nodes(n); // (val, index)
        map<int, vector<int>> indexMap;
        for(int i=0; i<n; i++) {
            nodes[i] = {vals[i], i};
            indexMap[vals[i]].push_back(i);
        }
        sort(nodes.begin(), nodes.end(), [&](pair<int,int>& a, pair<int,int>& b){
           if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        int answer = 0;
        for(auto tmp: indexMap){
            vector<int> indexes = tmp.second;
            int size = indexes.size();
            
            // connect
            for(auto now: indexes) 
                for(auto next: adj[now]) 
                    merge(now, next);
            
            // calc
            unordered_map<int, int> cnts;
            for(auto index: indexes) 
                cnts[find(index)]++;
            
            answer += size;
            for(auto cnt: cnts) 
                answer += (cnt.second * (cnt.second - 1)) / 2;
            
            // cout << tmp.first << " " << answer << endl;
        }
        
        return answer;
    }
};
