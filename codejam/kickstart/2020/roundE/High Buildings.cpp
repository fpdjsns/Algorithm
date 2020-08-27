/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef73
 * time complexity : O(N)
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(int N, int A, int B, int C) {
	if (A + B - C > N) return vector<int>(); // IMPOSSIBLE
	if (A - C == 0 && B - C == 0 && A + B - C != N) {
		if (C == 1) return vector<int>();
	}
	if (A < C || B < C) return vector<int>();
	vector<int> ans(N, N);
	int hide = N - (A + B - C);

	int hideLeft = (A - C == 0) ? 0 : hide;
	int hideMiddle = (C > 1) ? hide - hideLeft : 0;
	int hideRight = (B - C == 0) ? 0 : hide - hideMiddle - hideLeft;

	int index = 0;

	int tmp = N <= 2 ? 1 : 2;
	// set Andre
	for (int i = 0; i < A - C; i++)
		ans[index++] = tmp;
	for (int i = 0; i < hideLeft; i++)
		ans[index++] = 1;

	// set hiding among the tallest buildings
	ans[index++] = N;
	for (int i = 0; i < hideMiddle; i++)
		ans[index++] = 1;
	for (int i = 0; i < C - 1; i++)
		ans[index++] = N;

	// set Sule
	for (int i = 0; i < hideRight; i++)
		ans[index++] = 1;
	for (int i = 0; i < B - C; i++)
		ans[index++] = tmp;

	return ans;
}

int main() {

	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++) {
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		vector<int> ans = solve(N, A, B, C);
		cout << "Case #" << tc << ": ";
		if (ans.size() != N) printf("IMPOSSIBLE\n");
		else {
			for (int i = 0; i < N; i++) {
				printf("%d ", ans[i]);
			}
			cout << endl;
		}
	}
	return 0;
}
