/*
 * DFS와 BFS (1260) : https://www.acmicpc.net/problem/1260 너비우선탐색(BFS; Breadth First Search)
 * 시간복잡도 : O(V + E)
 */

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int graph[1001][1001]; //Graph
//N : Number of vertex
//M : Number of edge
//V : Start vertex number
int N, M, V;

//Breadth First Search
void BFS()
{
	queue<int> q;
	bool check[1001]; //Check that has passed
	int arr[1000]; //Save path
	int ind = 0;
	fill(&check[0], &check[N + 1], false);
	q.push(V);

	while (!q.empty())
	{
		int now = q.front(); //now : current node
		q.pop();
		if (check[now] == false) //If NOW is not passed yet
		{
			check[now] = true; //NOW has passed
			arr[ind++] = now; //Insert NOW onto the path

			for (int i = 1; i <= N; i++)
			{
				if (graph[now][i] == 1 && check[i] == false) //If connection & not passed
				{
					q.push(i); //push
				}
			}
		}
	}

	//Print path
	for (int i = 0; i < ind; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = 0;
			graph[j][i] = 0;
		}
	}
	//Edge connection
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	BFS(); //Breadth First Search
	return 0;
}
