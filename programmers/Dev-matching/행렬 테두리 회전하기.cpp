/** 
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77485
 * time complexity : NM + |queries| * (N + M) (let, N = |rows|, M = |columns|)
 * 분류 : 구현
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void set(int& value, int& before, int& minNum) {
	minNum = min(minNum, value);

	int tmp = value;
	value = before;
	before = tmp;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<vector<int>> array(rows, vector<int>(columns));
	for (int i = 0; i <rows; i++)
		for (int j = 0; j<columns; j++)
			array[i][j] = i * columns + j + 1;

	vector<int> answer;
	for (vector<int> query : queries) {
		int x1 = query[0] - 1;
		int y1 = query[1] - 1;
		int x2 = query[2] - 1;
		int y2 = query[3] - 1;
		int minNum = array[x1][y1];

		int before = array[x1 + 1][y1];
		for (int j = y1; j <= y2; j++) { set(array[x1][j], before, minNum); }
		for (int i = x1 + 1; i <= x2; i++) { set(array[i][y2], before, minNum); }
		for (int j = y2 - 1; j >= y1; j--) { set(array[x2][j], before, minNum); }
		for (int i = x2 - 1; i > x1; i--) { set(array[i][y1], before, minNum); }
		answer.push_back(minNum);
	}

	return answer;
}
