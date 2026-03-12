#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> board;
vector<vector<int>> dist;

int n, m;

int Xarr[4] = { 1,-1,0,0 };
int Yarr[4] = { 0,0,1,-1 };

int DFS(int start_x, int start_y) {

	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	dist[start_x][start_y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		if (cx == n - 1 && cy == m - 1) {
			return dist[cx][cy];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + Xarr[i];
			int ny = cy + Yarr[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (dist[nx][ny] == -1 && board[nx][ny] == '1')
				{
					q.push({ nx,ny });
					dist[nx][ny] = dist[cx][cy] + 1;
				}
			}
		}
	}
	return 0;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	board.resize(n);
	dist.assign(n, vector<int>(m,-1));

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	cout << DFS(0,0);
}