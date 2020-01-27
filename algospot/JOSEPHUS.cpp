
/**
 * problem : https://algospot.com/judge/problem/read/JOSEPHUS
 * time complexity : O(N^2)
 */
 
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*
 * N : 포위당한 사람
 * K : 자살하는 사람 번수
 */
pair<int, int> solve(int N, int K) {
	vector<int> people(N, -1);
	for (int i = 0; i < N; i++) people[i] = i + 1;
	
	int size = N;
	int dead = 0;
	
	while (size > 2) {
		people.erase(people.begin() + dead);
		size--;
		dead = (dead + K - 1) % size;
	}
	return { people[0], people[1] };
}

int main() {

	int C;
	cin >> C;

	while (C--) {
		int N, K;
		cin >> N >> K;
		pair<int, int> ans = solve(N, K);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
