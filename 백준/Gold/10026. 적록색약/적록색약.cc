#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int t;

vector<vector<bool>> visited;
vector<string> board;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int col, int row) {
	queue<pair<int,int>> q;
	q.push({ col,row });
	visited[col][row] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= t || ny < 0 || ny >= t)
				continue;
			else
			{
				if (visited[nx][ny] == 0 && board[nx][ny] == board[cx][cy])
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> t;

	board.resize(t);
	visited.assign(t, vector<bool>(t, 0));

	for (int i = 0; i < t; i++)
	{
		cin >> board[i];
	}

	int count_normal = 0;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			if (visited[i][j] == 0)
			{
				count_normal++;
				BFS(i, j);
			}
		}
	}

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			if (board[i][j] == 'G')
			{
				board[i][j] = 'R';
			}
		}
	}


	visited.assign(t, vector<bool>(t, 0));

	int count_Jang = 0;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			if (visited[i][j] == 0)
			{
				count_Jang++;
				BFS(i, j);
			}
		}
	}

	cout << count_normal << " " << count_Jang;
}