/**
 * problem : https://algospot.com/judge/problem/read/MORDOR
 * time complexity : O(NlogN + QlogQ)
 * algorithm : segment tree
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class SegmentTree {
private:
	const int ROOT = 1;
	const int MIN = 0;
	const int MAX = 20001;
	int N;
	vector<int> heights;

	// index 1부터 시작 
	// (최소 해발 고도, 최대 해발 고도)
	vector<pair<int, int>> nodes;

	pair<int, int> init(int ind, int s, int e) {
		if (s == e) // 단노드
			return nodes[ind] = { heights[s - 1], heights[e - 1] }; 

		int m = (s + e) / 2;
		pair<int, int> left = init(2 * ind, s, m);
		pair<int, int> right = init(2 * ind + 1, m + 1, e);
		return nodes[ind] = { min(left.first, right.first), max(left.second, right.second) };	
	}

	void init() {
		N = heights.size();
		int h = (int)ceil(log2(N));

		nodes = vector<pair<int,int>>(1 << (h + 1), { MAX, MIN });
		init(ROOT, 1, N);
	}

	pair<int, int> question(int ind, int s, int e, int a, int b) {

		if (b < s || a > e) return { MAX, MIN }; // 범위 벗어남
		if (a <= s && b >= e) return nodes[ind]; // [s,e]가 [a,b]에 완전 포함

		int m = (s + e) / 2;
		pair<int, int> left = question(2 * ind, s, m, a, b);
		pair<int, int> right = question(2 * ind + 1, m + 1, e, a, b);
		return { min(left.first, right.first), max(left.second, right.second) };
	}

public:
	SegmentTree(vector<int> heights) {
		this->heights = heights;
		init();
	}

	pair<int, int> question(int a, int b) {
		return question(ROOT, 1, N, a, b);
	}
};

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N, Q;
		cin >> N >> Q;
		vector<int> heights(N);
		for (int i = 0; i < N; i++) cin >> heights[i];
		SegmentTree st = SegmentTree(heights);
		int a, b;
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &a, &b);
			pair<int, int> ans = st.question(a + 1, b + 1);
			printf("%d\n", ans.second - ans.first);
		}
	}
	return 0;
}
