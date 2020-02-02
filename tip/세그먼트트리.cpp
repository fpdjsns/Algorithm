/*
 * 구간 합 구하기(2042) : https://www.acmicpc.net/problem/2042
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<long long> arr;

// O(2N). N= e-s
// tree. ind : tree 인덱스. s~e까지 범위.
void init(vector<long long>& tree, int ind, int s, int e)
{
	if (s == e)
		tree[ind] = arr[s];//단노드
	else
	{
		int m = (e + s) / 2;
		init(tree, 2 * ind, s, m);//왼쪽 자식
		init(tree, 2 * ind + 1, m + 1, e);//오른쪽 자식
		tree[ind] = tree[2 * ind] + tree[2 * ind + 1];//왼쪽 자식 + 오른쪽 자식
	}
}

//tree. ind : tree 인덱스. s~e까지 범위. a번째 수를 b로 바꿈
long long update(vector<long long>& tree, int ind, int s, int e, int a, int b)
{
	//범위 벗어남 -> 변하는 거 없음. 자기 노드 값 리턴
	if (a < s || e < a)
		return tree[ind];
	//찾음 -> 변한 노드 값 리턴
	if (s == e)
	{
		tree[ind] = b;//단노드
		return tree[ind];
	}
	int m = (e + s) / 2;
	long long left = update(tree, 2 * ind, s, m, a, b);
	long long right = update(tree, 2 * ind + 1, m + 1, e, a, b);
	tree[ind] = left + right;
	return tree[ind];
}

//a~b 구간의 합 리턴 
long long find(vector<long long>& tree, int ind, int s, int e, int a, int b)
{
	//범위 벗어나면 0 리턴 -> 더해도 변화 없으므로
	if (b < s || e < a)
		return 0;
	//s~e 범위가 a~b에 완벽하게 포함되면 해당 노드 값 리턴
	if (a <= s && e <= b)
		return tree[ind];
	//일부 포함되면 왼, 오 자식 노드 합 리턴
	int m = (e + s) / 2;
	long long left = find(tree, 2 * ind, s, m, a, b);
	long long right = find(tree, 2 * ind + 1, m + 1, e, a, b);
	return left + right;
}

int main()
{
	int n, m, k;
	int a, b;
	long long c;
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	vector<long long> tree(1 << (h + 1), 0);//구간의 합 저장
	arr.resize(n + 1);

	//입력
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	init(tree, 1, 1, n);//입력값으로 세그먼트 트리 생성

	//m+k개의 쿼리
	for (int i = 0; i < m + k; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
			update(tree, 1, 1, n, b, c);
		else
			printf("%lld\n", find(tree, 1, 1, n, b, c));
	}
	return 0;
}
