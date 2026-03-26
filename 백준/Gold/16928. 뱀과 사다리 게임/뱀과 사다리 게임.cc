#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[101];
int visited[101] = { 0 };
int dist[101] = { 0 };

void BFS() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	while (!q.empty())
	{
		int cx = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nx = cx + i;
			if (nx > 100)
				continue;
			else
			{
				int final_nx = board[nx];
				if (visited[final_nx] == 0)
				{
					visited[final_nx] = true;
					dist[final_nx] = dist[cx] + 1;
					q.push(final_nx);
				}
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++)
	{
		board[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int start, arrive;
		cin >> start >> arrive;

		board[start] = arrive;
	}

	for (int i = 0; i < m; i++)
	{
		int start, arrive;
		cin >> start >> arrive;

		board[start] = arrive;
	}


	BFS();

	cout << dist[100];
}