/**
 * problem: https://algospot.com/judge/problem/read/EDITORWARS
 * time complexity: O(N + M)
 * algorithm: union-find
 */
 
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#define MAX 1e6

using namespace std;
class Solution{
	vector<int> p;
	vector<int> dis;
	vector<int> size;
	int find(int n) {
		if (p[n] == -1) return n;
		return p[n] = find(p[n]);
	}

	int merge(int a, int b) {
		if (a == -1 || b == -1) return max(a, b);
		a = find(a);
		b = find(b);
		if (a == b) return a;
		size[b] += size[a];
		return p[a] = b;
	}

	bool acknowledge(int a, int b) {
		a = find(a);
		b = find(b);
		if (dis[a] == b) return false;

		// 적대 관계 세팅
		int pa = merge(a, b);
		int pb = merge(dis[a], dis[b]);
		dis[pa] = pb;
		if (pb != -1) dis[pb] = pa;
		return true;
	}
	bool dislike(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;

		// 적대 관계 세팅
		int pa = merge(a, dis[b]); 
		int pb = merge(b, dis[a]);
		dis[a] = b; dis[b] = a;
		return true;
	}

public:
	Solution() {}
	Solution(int N) {
		p = vector<int>(N, -1);
		dis = vector<int>(N, -1);
		size = vector<int>(N, 1);
	}

	bool query(string s, int a, int b) {
		if (s == "ACK") {
			return acknowledge(a, b);
		}
		else if(s == "DIS") {
			return dislike(a, b);
		} 
	}

	int getMaxSize() {
		int ret = 0;
		for (int node = 0; node < p.size(); node++) {
			if (p[node] == -1) { // 모임의 대장인 경우
				int enemy = dis[node];
				if (enemy > node) continue;
				int nowSize = size[node];
				int enemySize = (enemy == -1 ? 0 : size[enemy]);

				ret += max(nowSize, enemySize);
			}
		}
		return ret;
	}
};

int main() {

	int C;
	cin >> C;
	while (C--) {
		int N, M;
		cin >> N >> M;
		Solution solution = Solution(N);
		string s;
		int a, b;
		bool ans = true;
		for (int i = 1; i <= M; i++) {
			cin >> s >> a >> b;
			if (ans && !solution.query(s, a, b)) {
				cout << "CONTRADICTION AT " << i << endl;
				ans = false;
			}
		}
		if (ans)
			cout << "MAX PARTY SIZE IS " << solution.getMaxSize() << endl;
	}

	return 0;
}
