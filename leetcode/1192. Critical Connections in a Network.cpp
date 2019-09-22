/*
 * 문제 : https://leetcode.com/problems/critical-connections-in-a-network/
 * 시간복잡도 : O(V+E)
 * 알고리즘 : tarjan
 */
 
class Solution {
public:

    vector<vector<int>> edge;
    vector<int> num;
    vector<int> low;
    vector<vector<int>> ans;

    int t = 1;
    int tarjan(int now, int before) {
        int& ret = low[now];
        num[now] = t++;
        for (int i = 0; i<edge[now].size(); i++) {
            int next = edge[now][i];

            if (next == before) continue;
            if (num[next] == -1) { // not visit yet
                ret = min(ret, tarjan(next, now));

                if (low[next] > num[now]) {
                    ans.push_back({ now, next });
                }
            } else {
                ret = min(ret, num[next]);
            }
        }
        return ret;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        edge = vector<vector<int>>(n);
        num = vector<int>(n, -1);
        low = vector<int>(n, n);

		for (int i = 0; i<connections.size(); i++) {
          int a = connections[i][0];
          int b = connections[i][1];
          edge[a].push_back(b);
          edge[b].push_back(a);
        }

        for (int i = 0; i < n; i++) {
          sort(edge[i].begin(), edge[i].end());
        }

        tarjan(0, -1);

        return ans;
	}
};
