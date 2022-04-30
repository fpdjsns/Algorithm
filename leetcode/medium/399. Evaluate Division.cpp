/**
 * problem : https://leetcode.com/problems/evaluate-division/
 */
 
class Solution {
    unordered_map<string, unordered_map<string, double>> dist;
    
    double query(string start, string end) {
        queue<pair<string, double>> q;
        unordered_map<string, unordered_set<string>> check;
        q.push({start, 1});
        while(!q.empty()){
            string now = q.front().first;
            double value = q.front().second;
            q.pop();
            
            for(auto tmp: dist[now]) {
                string next = tmp.first;
                double nextValue = tmp.second;
                if(now == next) continue;
                if(check[now].find(next) != check[now].end()) continue;
                check[now].insert(next);
                dist[start][next] = value * nextValue;
                q.push({next, value * nextValue});
            }
        }
        
        if(dist[start].find(end) == dist[start].end()) 
            return -1;
        return dist[start][end];
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        dist.clear();
        for(int i=0; i<equations.size(); i++){
            auto equation = equations[i];
            string u = equation[0]; string v = equation[1];
            dist[u][v] = values[i];
            dist[v][u] = 1 / values[i];
            dist[u][u] = 1;
            dist[v][v] = 1;
        }
        
        vector<double> answer(queries.size(), -1);
        for(int i=0; i<queries.size(); i++){
            answer[i] = query(queries[i][0], queries[i][1]);
        }
        return answer;
    }
};
