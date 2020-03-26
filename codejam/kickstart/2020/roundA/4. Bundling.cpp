/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
 * time complexity : O(NlogM) // M = |word|
 * algorithm : Trie
 */

#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

class Node {
	char c;

public:
	int cnt; // 현재 노드가 문자열의 마지막인 문자열들의 개수
	vector<Node*> children;

	Node(char c) :c(c) {
		cnt = 0;
		children = vector<Node*>(26);
	}

	// c를 다음 문자로 가지는 node 자식을 가져오거나 없으면 생성 후 가져온다.
	Node* getNextOrAddNodeWhenNull (char c) {
		if (children[c - 'A'] == NULL) // 만약 자식이 없는 경우
			children[c - 'A'] = new Node(c); // 만든다.
		return children[c - 'A'];
	}
};

class Trie {
	Node root;
	int ans = 0;
	int K = 0;

	// node = 탐색 위치
	// depth = 트리의 depth, prefix의 길이와 같다.
	int solve(int depth, Node* node) {
		int hasPrefixStringCnt = node->cnt;
		for (int i = 0; i < node->children.size(); i++) {
			Node* next = node->children[i];
			if (next == NULL) continue;
			hasPrefixStringCnt += solve(depth + 1, next);
		}


		// 정답에 서브트리가 가지고 있는 문자열들 중 아직 분류되지 않은 문자열들을 
		// K개씩 분류할 때의 개수를 더한다.
		ans += depth * (hasPrefixStringCnt / K);
		return hasPrefixStringCnt % K; // K개씩 분류할 때 나머지 
	}
public: 
	Trie() : root(Node(' ')) {}
	void add(string s) {
		Node* node = &root;
		for (int i = 0; i < s.size(); i++) {
			char now = s[i];
			node = node->getNextOrAddNodeWhenNull(now);
		}
		node->cnt++;
	}

	int solve(int _K) {
		ans = 0;
		K = _K;
		solve(0, &root);
		return ans;
	}
};

int solve(int N, int K, vector<string> arr) {
	Trie trie = Trie();
	for (int i = 0; i < N; i++) {
		trie.add(arr[i]);
	}
	return trie.solve(K);
}

int main() {
	int T;
	cin >> T;
	int N, K;
	for (int c = 1; c <= T; c++) {
		cin >> N >> K;
		vector<string> M(N);
		for (int i = 0; i < N; i++) cin >> M[i];
		cout << "Case #" << c << ": " << solve(N, K, M) << endl;
	}

	return 0;
}
