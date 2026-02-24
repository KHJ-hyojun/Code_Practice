#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

void BFS(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty())
	{
		
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (board[nx][ny] == 0 || visited[nx][ny])
				continue;

			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	while (T--)
	{
		int k;
		cin >> m >> n >> k;
		board.assign(n, vector<int>(m));
		visited.assign(n, vector<bool>(m, false));

		for (int _ = 0; _ < k; _++)
		{
			int a, b;
			cin >> a >> b;

			board[b][a] = 1;
		}

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					BFS(i, j);
					count++;
				}
			}
		}

		cout << count << "\n";
	}

	
}