/**
 * problem : https://www.algospot.com/judge/problem/read/WORDCHAIN
 * time complexity : O(aN). a = count of alphabet(26), N = |words|
 * algorithm : Euler circuit
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string.h>
#define ALPHA 26

using namespace std;


vector<int> indegree;
vector<int> outdegree;
vector<vector<vector<string>>> graphWords;

vector<vector<int>> makeGraph(const vector<string>& words) {
	vector<vector<int>> adj(ALPHA, vector<int>(ALPHA));
	for (int i = 0; i < words.size(); i++) {
		int s = words[i][0] - 'a';
		int e = words[i][words[i].size() - 1] - 'a';
		graphWords[s][e].push_back(words[i]);
		adj[s][e]++;
		indegree[e]++;
		outdegree[s]++;
	}
	return adj;
}

vector<int> ans;
bool canAns;

// 오일러 회로가 가능한지는 이전에 확인한 후 실행되는 함수
void tryEulerCircuit(int now, vector<vector<int>>& adj) {
	for (int next = 0; next < adj[now].size(); next++) {
		while (adj[now][next]) {
			adj[now][next]--; // delete edge
			tryEulerCircuit(next, adj);
		}
	}
	ans.push_back(now);
}

bool checkEuler(const vector<int>& indegree, const vector<int>& outdegree) {
	int startVertexCnt = 0; // outdegree = indegree + 1
	int endVertexCnt = 0; // indegree = outdegree + 1
	for (int i = 0; i < ALPHA; i++) {
		int diff = indegree[i] - outdegree[i];
		if (diff < -1 || 1 < diff) return false;
		startVertexCnt += (diff == -1);
		endVertexCnt += (diff == 1);
	}
	if (startVertexCnt == 1 && endVertexCnt == 1) return true;
	if (startVertexCnt == 0 && endVertexCnt == 0) return true;
	return false;
}

vector<string> solve(const vector<string>& words) {
	// init
	indegree = vector<int>(ALPHA);
	outdegree = vector<int>(ALPHA);
	graphWords = vector<vector<vector<string>>>(ALPHA, vector<vector<string>>(ALPHA));
	ans = vector<int>();

	// set edge
	vector<vector<int>> adj = makeGraph(words);

	// check avaliable euler
	if(!checkEuler(indegree, outdegree)) return vector<string>();

	// find start index
	int startInd = -1;
	for (int i = 0; i < ALPHA; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			startInd = i;
			break;
		}
	}
	if (startInd == -1) {
		for (int i = 0; i < ALPHA; i++) {
			if (outdegree[i] == 0) continue;
			startInd = i;
			break;
		}
	}
	if (startInd == -1) return vector<string>();
	tryEulerCircuit(startInd, adj);
	if (ans.size() != words.size() + 1) return vector<string>();

	// set words
	vector<string> ansWords(ans.size());
	reverse(ans.begin(), ans.end());
	for (int i = 1; i < ans.size(); i++) {
		int s = ans[i-1], e = ans[i];
		ansWords[i] = graphWords[s][e].back();
		graphWords[s][e].pop_back();
	}
	return ansWords;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> words(N);
		for (int i = 0; i < N; i++) cin >> words[i];
		vector<string> ans = solve(words);
		if (ans.size() == 0) cout << "IMPOSSIBLE";
		else for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
