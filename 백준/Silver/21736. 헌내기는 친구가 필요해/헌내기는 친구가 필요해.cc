#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Xarr[4] = { 1,-1,0,0 };
int Yarr[4] = { 0,0,1,-1 };

int n, m;

string board[605];
bool visited[605][605];

int result = 0;

void DFS(int col, int row) {
	for (int i = 0; i < 4; i++)
	{
		int nx = col + Xarr[i];
		int ny = row + Yarr[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny] == 1) continue;
		if (board[nx][ny] == 'X') continue;

		visited[nx][ny] = true;
		if (board[nx][ny] == 'P') result++;
		DFS(nx, ny);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'I')
			{
				visited[i][j] = true;
				DFS(i, j);
			}
		}
	}

	if (result == 0) cout << "TT";
	else cout << result;
}