#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> board;

int BFS(int num) {
	queue<int> q;

	vector<int> dist(n + 1, -1);

	q.push(num);
	dist[num] = 0;

	int bacon_sum = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < board[curr].size(); i++)
		{
			int nx = board[curr][i];
			if (dist[nx] == -1)
			{
				dist[nx] = dist[curr] + 1;
				bacon_sum += dist[nx];
				q.push(nx);
				
				
			}
		}
	}
	return bacon_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	board.assign(n + 1, vector<int>());

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		board[a].push_back(b);
		board[b].push_back(a);
	}
	
	vector<int> result(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		result[i] = BFS(i);
	}

	int min_bacon = 99999999;
	int index = 0;

	for (int i = 1; i <= n; i++)
	{
		if (result[i] < min_bacon)
		{
			min_bacon = result[i];
			index = i;
		}
	}
	cout << index;
}