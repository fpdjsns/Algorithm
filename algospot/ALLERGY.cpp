/*
 * 문제 : https://algospot.com/judge/problem/read/ALLERGY
 * 알고리즘 : Combination search
 */

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int>> friends; // i번 음식을 먹을 수 있는 친구들
vector<vector<int>> foods; // i번 친구가 먹을 수 있는 음식들
int n, m;
int best;

void solve(vector<int>& edible, int cnt) {
	if (cnt >= best) return;
	int ind = 0;
	while (ind < n && edible[ind] > 0) ind++;
	if (ind == n) { 
		best = min(best, cnt); 
		return; 
	}
	for (int i = 0; i < foods[ind].size(); i++) {
		int food = foods[ind][i];
		for (int j = 0; j < friends[food].size(); j++)
			edible[friends[food][j]]++;
		solve(edible, cnt + 1);
		for (int j = 0; j < friends[food].size(); j++)
			edible[friends[food][j]]--;
	}
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		best = 1e9;
		map<string, int> friendMap;
		friends = vector<vector<int>>(m, vector<int>());
		
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			friendMap[str] = i;
		}

		foods = vector<vector<int>>(n, vector<int>());
		for (int i = 0; i < m; i++) {
			int cnt = 0;
			cin >> cnt;
			for (int j = 0; j < cnt; j++) {
				cin >> str; 
				int ind = friendMap[str];
				foods[ind].push_back(i);
				friends[i].push_back(ind);
			}
		}
		vector<int> edible(n, 0);
		solve(edible, 0);
		cout << best << endl;
	}
	return 0;
}
