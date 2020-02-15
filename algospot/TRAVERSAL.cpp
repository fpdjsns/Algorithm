/**
* problem : https://algospot.com/judge/problem/read/TRAVERSAL
* time complexity : O(N^2)
* data structure : tree
*/

#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// arr[begin, end)
vector<int> getSubVector(vector<int> arr, int begin, int end) {
	return vector<int>(arr.begin() + begin, arr.begin() + end);
}

void postOrder(vector<int> preArr, vector<int> inArr) {
	int N = preArr.size();
	if (N == 1) cout << preArr[0] << " ";
	if (N <= 1) return;

	// 루트는 전위순회했을 때 가장 먼저 나오는 노드
	int root = preArr[0];

	// 왼쪽 자식 노드들이 없는 경우
	if (inArr[0] == preArr[0]) {
		// 다음 배열들부터 다시 탐색
		postOrder(getSubVector(preArr, 1, N), getSubVector(inArr, 1, N));
	}
	else {
		// 중위 순회 배열에서 root 노드 인덱스 = 왼쪽 자식 노드들의 개수
		int inArrRootInd = 0;
		while (inArrRootInd < N && inArr[inArrRootInd] != root) inArrRootInd++;

		// 1. 왼쪽 자식노드들 후위 순회 = 왼쪽 자식 노드 방문
		postOrder(getSubVector(preArr, 1, inArrRootInd + 1), getSubVector(inArr, 0, inArrRootInd));
		// 2. 오른쪽 자식노드들 후위 순회 = 오른쪽 자식 노드 방문
		postOrder(getSubVector(preArr, inArrRootInd + 1, N), getSubVector(inArr, inArrRootInd + 1, N));
	}
	// 3. 루트 방문
	cout << root << " ";
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int N; cin >> N;
		vector<int> preArr(N);
		vector<int> inArr(N);
		for (int i = 0; i < N; i++) cin >> preArr[i];
		for (int i = 0; i < N; i++) cin >> inArr[i];
		postOrder(preArr, inArr);
		cout << endl;
	}
	return 0;
}
