#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_val = 0;
int n, m;
int board[501][501];
bool visited[501][501] = { false };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


void DFS(int cx, int cy,int depth, int current_sum) {

	if (depth == 4)
	{
		if (current_sum > max_val) max_val = current_sum;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dx[i];
		int ny = cy + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (!visited[nx][ny])
		{
			visited[nx][ny] = true;
			DFS(nx, ny, depth + 1, current_sum + board[nx][ny]);
			visited[nx][ny] = false;
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			visited[i][j] = true;
			DFS(i, j, 1, board[i][j]);
			visited[i][j] = false;

			int wings_sum = 0;
			int min_wing = 10000;
			int wing_count = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					wings_sum += board[nx][ny];
					min_wing = min(min_wing, board[nx][ny]);
					wing_count++;
				}
			}

			if (wing_count == 4) wings_sum -= min_wing;

			if (wing_count >= 3)
			{
				max_val = max(max_val, wings_sum + board[i][j]);
			}
		}
	}
	cout << max_val;
}