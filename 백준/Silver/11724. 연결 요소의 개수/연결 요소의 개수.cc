#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<bool> visited;

void DFS(int node) {

	visited[node] = true;

	for (int nn : board[node])
	{
		if (!visited[nn])
			DFS(nn);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	board.assign(n+1, vector<int>());
	visited.assign(n+1, 0);


	for (int _ = 0; _ < m; _++)
	{
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}

	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			result++;
			DFS(i);
		}
	}
	cout << result;

}