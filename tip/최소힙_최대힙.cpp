#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * input example
 * 5
 * 3 1 5 4 2
 */
int main(int argc, char** argv)
{
	priority_queue<int> min_heap; // 최대 힙
	priority_queue<int, vector<int>, greater<int>> max_heap; // 최소 힙

	int n, tmp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		min_heap.push(tmp);
		max_heap.push(tmp);
	}

	while (!min_heap.empty()) {
		cout << min_heap.top() << " ";
		min_heap.pop();
	}
	cout << endl;

	while (!max_heap.empty()) {
		cout << max_heap.top() << " ";
		max_heap.pop();
	}

	return 0;
}
