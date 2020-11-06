/**
 * problem : https://leetcode.com/problems/minimum-height-trees/
 * algorithm : BFS
 * time complexity : O(N)
 */
class Solution {
    
    vector<int> beforeNode;
    vector<int> maxDistNodes(int N, int start, vector<vector<int>>& edges){
        beforeNode = vector<int>(N);
        
        queue<int> q;
        vector<bool> visits(N, false);
        vector<int> dist(N, 0);
        q.push(start);
        visits[start] = true;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(auto next: edges[now]){
                if(visits[next]) continue;
                visits[next] = true;
                if(dist[next] < dist[now] + 1){
                    beforeNode[next] = now;
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
        vector<int> lasts;
        int maxDist = 0;
        for(int i=0;i<N;i++){
            if(dist[i] > maxDist){
                lasts = vector<int>();
                maxDist = dist[i];
            }
            if(dist[i] == maxDist)
                lasts.push_back(i);
        }
        
        return lasts;
    }
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> newEdges(n);
        for(int i=0;i<edges.size();i++){
            newEdges[edges[i][0]].push_back(edges[i][1]);
            newEdges[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> lasts = maxDistNodes(n, 0, newEdges);
        set<int> answerSet;
        for(auto start : lasts) {
            vector<int> lastNodes = maxDistNodes(n, start, newEdges);
            for(auto last: lastNodes){
                int now = last;
                vector<int> tmpNodes;
                while(now != start) { 
                    tmpNodes.push_back(now);
                    now = beforeNode[now];
                }
                tmpNodes.push_back(start);
                    
                int middle = tmpNodes.size()/2;
                if(tmpNodes.size() < 1) continue;
                answerSet.insert(tmpNodes[middle]);
                if(tmpNodes.size() % 2 == 0) answerSet.insert(tmpNodes[middle-1]);
            }
        }
        
        vector<int> answer;
        for(set<int>::iterator it = answerSet.begin(); it != answerSet.end(); it++){
            answer.push_back(*it);
        }
        
        return answer;
    }
};
