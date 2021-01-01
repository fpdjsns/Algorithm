/**
 * problem : https://www.acmicpc.net/problem/20528
 * time complexity : O(N)
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;
	string tmp;
	cin >> tmp;
	char startChar = tmp[0];

	bool answer = true;
	for (int i = 1; i < N; i++) {
		cin >> tmp;
		if (startChar != tmp[0]) answer = false;
	}

	printf("%d\n", answer);
	return 0;
}
