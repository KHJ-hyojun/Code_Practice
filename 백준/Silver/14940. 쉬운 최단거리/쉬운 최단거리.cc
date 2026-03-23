#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<int>> result;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

void BFS(int col, int row) {
	queue<pair<int, int>> q;

	q.push({ col,row });
	visited[col][row] = true;

	result[col][row] = 0;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (visited[nx][ny] == 0 && board[nx][ny] == 1)
				{
					q.push({ nx,ny });

					visited[nx][ny] = true;

					result[nx][ny] = result[cx][cy] + 1;
				}
			}
		}

	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int start[2] = { 0,0 };

	board.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, 0));
	result.assign(n, vector<int>(m, -1));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;

			if (x == 2)
			{
				start[0] = i;
				start[1] = j;
				board[i][j] = 2;
			}
			else if (x == 1)
				board[i][j] = 1;
			else
			{
				board[i][j] = 0;
				result[i][j] = 0;
			}
		}
	}

	int startx = start[0];
	int starty = start[1];

	BFS(startx, starty);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
				cout << result[i][j] << " ";
		}
		cout << "\n";
	}

}