/**
 * problem : https://algospot.com/judge/problem/read/FORTRESS
 * time complexity : O(N^2 logN)
 * data structure : Tree
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Castle {
	int x;
	int y;
	int r;
public:

	Castle() {}
	Castle(int _x, int _y, int _r) {
		x = _x; y = _y; r = _r;
	}

	// 성벽의 가장 왼쪽 x 좌표를 기준으로 오름차순 정렬
	bool operator<(Castle c) const {
		return x - r < c.x - c.r;
	}

	// 현재 원(this)이 c 성을 포함가능한지
	bool isInclude(Castle c) {
		// 두 원의 중심선 사이의 거리 + c의 반지름 < this 원의 반지름
		int centerDist = sqrt((y - c.y) * (y - c.y) + (x - c.x) * (x - c.x));
		return (centerDist + c.r) < r;
	}
};

class Node {
	Castle castle;
public:
	vector<Node*> childrens;

	Node() {}
	Node(Castle castle) : castle(castle) {}

	// c를 포함가능하다면 c를 자식으로 둘 수 있다.
	bool canChild(Castle c) {
		return castle.isInclude(c);
	}

	// node를 자식 노드로 추가한다.
	void addChild(Node* node) {
		childrens.push_back(node);
	}
};

int ans = 0;

// node 성벽 내부(자식 노드들)에 있는 성벽들 중 가장 많이 넘어야 하는 두 지점 사이의 성벽 개수
int getMaxCnt(Node* node) {
	vector<Node*> childrens = node->childrens;

	// 리프 노드인 경우
	if (childrens.size() == 0) return 0;

	vector<int> cnts(childrens.size());
	for (int i = 0; i < childrens.size(); i++) {
		// 자식 노드의 성벽을 한 번 뛰어넘어야 하므로 + 1
		cnts[i] = getMaxCnt(childrens[i]) + 1;
	}
	// 내림차순 정렬
	sort(cnts.begin(), cnts.end(), [cnts](int& a, int & b) { return a > b; });
	if (cnts.size() > 2) { // 자식이 2개 이상이라면 
		// 성벽을 넘는 횟수가 가장 많은 2개를 더한 값을 정답과 비교하여 갱신
		// 두 성벽을 이동하는 횟수가 정답인지 체크하는 과정.
		ans = max(ans, cnts[0] + cnts[1]);
	}
 
	return  cnts[0];
}

int solve(vector<Castle> castles) {
	int N = castles.size();
	ans = 0; // 정답 초기화

	// x-r 기준으로 오름차순 정렬
	// 노드들이 항상 리프 노드에 추가될 수 있게 한다.
	sort(castles.begin(), castles.end());

	Node root = Node(castles[0]);
	vector<Node> nodes(N);
	for (int i = 1; i < N; i++) {
		Node* node = &root;
		Castle now = castles[i];

		// now를 child로 가질 수 있는 노드를 찾을 때까지
		while (node->canChild(now) && node->childrens.size() > 0) {
			vector<Node*> childrens = node->childrens;
			
			bool isFind = false;
			for (int j = 0; j < childrens.size(); j++) {
				if (childrens[j]->canChild(now)) {
					node = childrens[j];
					isFind = true;
				}
				if (isFind) break;
			}
			if (!isFind) break;
		}

		// now를 자식으로 추가
		nodes[i] = Node(now);
		node->addChild(&nodes[i]);
	}

	ans = max(ans, getMaxCnt(&root));
	return ans;
}

int main()
{
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		int x, y, r;
		vector<Castle> castles(N);
		for (int i = 0; i < N; i++) {
			cin >> x >> y >> r;
			castles[i] = Castle(x, y, r);
		}
		cout << solve(castles) << endl;
	}
}
