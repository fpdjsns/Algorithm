/**
 * problem : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 * algorithm : Union-Find
 * time complexity : O(NlogN). N = |connections|
 */
 
class Solution {
	int INIT = -1;
	vector<int> p;

	int find(int n) {
		if (p[n] == INIT) return n;
		return p[n] = find(p[n]);
	}

	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b)
			p[a] = b;
	}

public:
	int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
		p = vector<int>(n, INIT);
		for (int i = 0; i < connections.size(); i++) {
			merge(connections[i][0], connections[i][1]);
		}

		set<int> parentSet;
		for (int i = 0; i < n; i++) {
			parentSet.insert(find(i));
		}
		return parentSet.size() - 1;
	}
};
