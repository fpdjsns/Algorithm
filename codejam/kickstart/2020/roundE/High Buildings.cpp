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
		if (C <= 1) return vector<int>();
	}
	vector<int> ans(N, N);
	int hide = N - (A + B - C);

	int hideLeft = (A - C == 0) ? 0 : hide;
	int hideRight = (B - C == 0) ? 0 : hide - hideLeft;
	int hideMiddle = hide - hideLeft - hideRight;

	// set Andre
	for (int i = 0; i < A - C + hideLeft; i++) {
		ans[i] = i + 1 + hideLeft;
		if (i >= A - C)
			ans[i] = 1;
	}

	// set hiding among the tallest buildings
	for (int i = 0; i < hideMiddle; i++) {
		ans[i + A - C + hideLeft + 1] = 1;
	}

	// set Sule
	int tmp = 1;
	for (int i = N - 1; i >= N - (B - C + hideRight); i--) {
		ans[i] = tmp + hideRight;
		if (i < A + hide)
			ans[i] = 1;
		tmp++;
	}
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
