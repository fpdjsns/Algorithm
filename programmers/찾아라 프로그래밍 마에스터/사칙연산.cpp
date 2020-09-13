/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/1843
 * algorithm : DP
 * time complexity : O(N^3)
 * 
 **/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MIN -2e9
#define MAX 2e9

using namespace std;

vector<vector<int>> dMax;
vector<vector<int>> dMin;
vector<string> Arr;

int goMin(int s, int e);

int getNum(string s){
	int num = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		num += (s[i] - '0')*mul;
		mul *= 10;
	}
	return num;
}

//dMax[s][e]
int goMax(int s, int e){
	int& ret = dMax[s][e];
	if (ret != MIN) return ret;
	int now = getNum(Arr[s]);
	if (s == e)
		return ret = now;

	for (int i = s + 1; i < e; i+=2) {
		if (Arr[i] == "+")
			ret = max(ret, goMax(s, i - 1) + goMax(i + 1, e));
		else
			ret = max(ret, goMax(s, i - 1) - goMin(i + 1, e));
	}
	return ret;
}

//dMin[s][e]
int goMin(int s, int e){
	int& ret = dMin[s][e];
	if (ret != MAX) return ret;
	int now = getNum(Arr[s]);
	if (s == e)
		return ret = now;

	for (int i = s + 1; i < e; i+=2){
		if (Arr[i] == "+")
			ret = min(ret, goMin(s, i - 1) + goMin(i + 1, e));
		else
			ret = min(ret, goMin(s, i - 1) - goMax(i + 1, e));
	}
	return ret;
}

int solution(vector<string> arr)
{
	int answer = 1;
	int n = arr.size();

	Arr = arr;
	dMax.resize(n, vector<int>(n, MIN));
	dMin.resize(n, vector<int>(n, MAX));
	goMax(0, n - 1);

	return dMax[0][n - 1];
}
