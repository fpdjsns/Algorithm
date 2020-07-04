/**
 * problem : https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
 * algorithm : Floyd
 * time complexity : O(V^3)
 */

class Solution {
public:

    int MAX = 100;
    int len = 0;
    vector<vector<int>> adj = vector<vector<int>>();
    vector<vector<int>> dist = vector<vector<int>>();

    int DP() {
        //d[state][now]
        vector<vector<int>> d(1 << len, vector<int>(len, MAX));
        for(int i=0;i<len;i++)
            d[1<<i][i] = 0; // i->i 

        for(int state=0;state < (1<<len); state++){
            for(int s = 0;s<len;s++){
                for(int e=0;e<len;e++){
                    int sState = 1<<s;
                    int eState = 1<<e;
                    if((state & sState) != 0 && (state & eState) == 0) // satisfaction of conditions (state)
                        d[state|eState][e] = min(d[state|eState][e], d[state][s] + dist[s][e]);
                }
            }
        }

        int ans = MAX;
        int allVisitState = (1<<len)-1;
        for(int now = 0; now<len; now++){
            ans = min(ans, d[allVisitState][now]); // all nodes visit && end point(now)
        }
        return ans;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        //initialize
        len = graph.size();
        adj = graph;
        dist.resize(len, vector<int>(len, MAX));

        for(int now = 0;now<len;now++){
            for(int j = 0;j<graph[now].size();j++){
                int next = graph[now][j];
                dist[now][next] = 1;
            }
        }

        //Floyd
        for (int k = 0; k < len; k++) {
            for (int now = 0; now < len; now++) {
                for (int next = 0; next < len; next++) {
                    dist[now][next] = min(dist[now][next], dist[now][k] + dist[k][next]);
                }
            }
        }

        //solve -> with DP
        int ans = DP();

        return ans;
    }
};
