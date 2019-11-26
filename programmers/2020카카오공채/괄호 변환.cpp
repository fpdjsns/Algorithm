/*
 * programmers - 2020카카오공채 - 괄호 변환
 * 문제 : https://programmers.co.kr/learn/courses/30/lessons/60058
 * 시간복잡도 :
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

string calculateU(string u) {
	stack<char> st;
	int cnt = 0;
	bool isCollect = true;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) {
			isCollect = false;
			break;
		}
	}

	if (isCollect) return u;
	string newU = "";
	for (int i = 1; i < u.size() - 1; i++) {
		if (u[i] == '(') newU += ')';
		else newU += '(';
	}

	return "(" + newU + ")";
}

pair<string, string> divide(string p) {
	if (p.size() == 0) return { "", "" };

	int ind = 0;
	int cnt = 0;

	while (ind < p.size() && (ind == 0 || cnt != 0 )) {
		if (p[ind++] == '(') cnt++;
		else cnt--;
	}
	string u = p.substr(0, ind);
	string v = p.substr(ind, p.size() - ind);
	return { u, v };
}

string solution(string p) {
	if (p.empty()) return p;
	pair<string, string> uv = divide(p);
	string u = uv.first;
	string v = uv.second;
	return calculateU(u) + solution(v);
}
