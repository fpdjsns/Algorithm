/**
 * problem : https://www.acmicpc.net/problem/13460
 * algorithm : BFS
 */
 
#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 10

using namespace std;

struct point
{
	int x, y;
};

int main(int argc, char** argv)
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	
	point R, B;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
			{
				arr[i][j] = '.';
				B.x = i; B.y = j;
			}
			if (arr[i][j] == 'R')
			{
				arr[i][j] = '.';
				R.x = i; R.y = j;
			}
		}
	}
	queue<pair<pair<point, point>, int>> q; //R,B,cnt
	bool check[MAX][MAX][MAX][MAX] = { false };//(Rx, Ry, Bx, By) 탐색했는지 여부 저장
	check[R.x][R.y][B.x][B.y] = true;

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	q.push({ {R,B}, 0 });
	while (!q.empty())
	{
		R = q.front().first.first;
		B = q.front().first.second;
		int cnt = q.front().second + 1;
		q.pop();
		if (cnt > 10) continue;//10번 넘어가면 안됨

		for (int i = 0; i < 4; i++)
		{
			point nR = R;
			point nB = B;

			while (arr[nR.x + dx[i]][nR.y + dy[i]] != '#')
			{
				nR.x += dx[i];
				nR.y += dy[i];
				if (arr[nR.x][nR.y] == 'O') break;
			}
			while (arr[nB.x + dx[i]][nB.y + dy[i]] != '#') 
			{
				nB.x += dx[i];
				nB.y += dy[i];
				if (arr[nB.x][nB.y] == 'O') break;
			}

			//파란 공 나옴
			if (arr[nB.x][nB.y] == 'O')
				continue;
			//빨간 공만 빠져나옴
			if (arr[nR.x][nR.y] == 'O')
			{
				cout << cnt;
				return 0;//종료
			}
			
			//겹친 경우
			if (nR.x == nB.x && nR.y == nB.y)
			{
				if (dx[i] != 0)
				{
					if (R.x * dx[i] > B.x * dx[i]) nB.x -= dx[i];
					else nR.x -= dx[i];
				}
				else
				{
					if (R.y * dy[i] > B.y * dy[i]) nB.y -= dy[i];
					else nR.y -= dy[i];
				}
			}

			//방문 안한 것만 큐에 push
			if (check[nR.x][nR.y][nB.x][nB.y]) continue;
			q.push({ { nR,nB }, cnt });
			check[nR.x][nR.y][nB.x][nB.y] = true;
		}
	}
	cout << "-1";
	
	return 0;
}
