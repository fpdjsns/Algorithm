/**
 * problem : https://www.algospot.com/judge/problem/read/DICTIONARY
 * time complexity : O(NL). N = |words|, L = |words[i]|
 * algorithm : Topological Sort
 */
 
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string.h>
#define ALPHA 26

using namespace std;

// O(NL). N = |words|, L = |words[i]|
vector<vector<bool>> makeGraph(const vector<string>& words) {
	vector<vector<bool>> adj(ALPHA, vector<bool>(ALPHA, false));
	for (int i = 1; i < words.size(); i++) {
		string a = words[i - 1];
		string b = words[i];
		for (int j = 0; j < min(a.size(), b.size()); j++) {
			if (a[j] == b[j]) continue;
			adj[a[j] - 'a'][b[j] - 'a'] = true;
			break;
		}
	}
	return adj;
}

vector<bool> check;
vector<int> ans;

// O(N). N = number of Vertex. ALPHA(26)
void dfs(int ind, const vector<vector<bool>>& adj) {
	if (ind < 0 || adj.size() <= ind)
		return;
	check[ind] = true;
	for (int i = 0; i < ALPHA; i++)
		if (adj[ind][i] && !check[i])
			dfs(i, adj);
	ans.push_back(ind);
}

vector<int> solve(const vector<string>& words) {
	// init
	check = vector<bool>(ALPHA, false);
	ans = vector<int>();

	// set edge
	vector<vector<bool>> adj = makeGraph(words);

	// set answer
	for (int i = 0; i < ALPHA; i++) {
		if (check[i]) continue;
		dfs(i, adj);
	}
	reverse(ans.begin(), ans.end());

	// check DAG
	for (int i = 0; i < ALPHA; i++) {
		for (int j = i+1; j < ALPHA; j++) {
			// has reverse edge
			if (adj[ans[j]][ans[i]])
				return vector<int>();
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> words(N);
		for (int i = 0; i < N; i++) cin >> words[i];
		vector<int> ans = solve(words);
		if (ans.size() == 0) cout << "INVALID HYPOTHESIS";
		else for (int i = 0; i < ans.size(); i++) cout << (char)(ans[i] + 'a');
		cout << endl;
	}
	return 0;
}
