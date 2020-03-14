/**
 * problem: https://algospot.com/judge/problem/read/MEASURETIME
 * algorithm : Fenwick Tree
 * time complexity: O(N * logM) // let, M = tree.size() 
 */
 
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 1e6

using namespace std;

// let, M = size
struct Fenwick {
	vector<int> tree;
	int size;

	Fenwick(int size) : tree(size + 1), size(size) {}

	/** 
	 * arr[0..] 합 구하기 
	 * O(logM)
	 */
	int getTotalSum() {
		return getSum(size - 1);
	}

	/**
	 * arr[0, ind] 합 구하기
	 * O(log(ind))
	 */
	int getSum(int ind) {
		int ans = 0;
		ind++;
		while (ind > 0) {
			ans += tree[ind];
			// 가장 뒤에 있는 1 빼기
			ind &= (ind - 1);
		}
		return ans;
	}

	/**
	 * arr[ind]에 n을 추가
	 * O(log(ind))
	 */
	void update(int ind, int n) {
		ind++;
		while (ind < tree.size()) {
			tree[ind] += n;
			// 가장 뒤에 있는 1 더하기
			ind += (ind & -ind);
		}
	}
};

long long solve(vector<int> arr) {
	Fenwick fw(MAX);
	long long ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans += fw.getTotalSum() - fw.getSum(arr[i]);
		fw.update(arr[i], 1); // arr[i]에 1개 추가됨을 의미
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) cin >> arr[i];
		cout << solve(arr) << endl;
	}
	return 0;
}
