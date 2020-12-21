/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4ed8
 * time complexity : O(NlogN)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, X;
		cin >> N >> X;
		vector<pair<int, int>> people(N);
		int need;
		for (int i = 0; i<N; i++) {
			cin >> need;
			people[i] = { (need + X - 1) / X, i + 1 };
		}
		sort(people.begin(), people.end());

		printf("Case #%d: ", t);
		for (auto person : people) {
			printf(" %d", person.second);
		}
		printf("\n");
	}
}
