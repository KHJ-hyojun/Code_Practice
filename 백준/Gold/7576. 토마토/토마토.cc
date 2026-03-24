#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int board[1001][1001];

int col, row;

queue<pair<int, int>> q;

void BFS() {
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col) 
				continue;
			else
			{
				if (board[nx][ny] == 0)
				{
					board[nx][ny] = board[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

bool result = true;
int max_val = 0;

void Val() {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 0)
			{
				result = false;
				return;
			}
			else
			{
				if (board[i][j] > max_val) max_val = board[i][j];
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> col >> row;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) q.push({ i,j });
		}
	}

	BFS();
	Val();

	if (result == false) cout << -1;
	else cout << max_val - 1;
}