#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<bool> visited;

string resultd;

void DFS(int node)
{
	resultd += to_string(node) + " ";
	
	visited[node] = true;

	for (int neighbor : board[node])
	{
		if (!visited[neighbor])
		{
			DFS(neighbor);
		}
	}
}

string BFS(int node)
{
	string result = "";
	queue<int> q;

	visited.assign(visited.size(), false);
	q.push(node);
	visited[node] = true;


	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		result += to_string(x) + " ";

		for (int y : board[x])
		{
			if (!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
	return result;

}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	board.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);

	
	// 간선연결하기
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		board[a].push_back(b);
		board[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(board[i].begin(), board[i].end());
	//실행하기
	DFS(v);
	cout << resultd << "\n";
	cout << BFS(v);
}