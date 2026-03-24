#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tomawi {
	int x;
	int y;
	int z;
	tomawi(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int dz[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 0,0,0,0,1,-1 };

int n, m, h;
int board[101][101][101];
queue<tomawi> q;

bool result = true;
int max_val = 0;

void Val()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (board[k][j][i] == 0)
				{
					result = false;
					return;
				}
				else
				{
					if (board[k][j][i] > max_val) max_val = board[k][j][i];
				}
			}
		}
	}
}


void BFS() {

	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cz = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) 
				continue;
			else
			{
				if (board[nx][ny][nz] == 0)
				{
					board[nx][ny][nz] = 1 + board[cx][cy][cz];
					q.push(tomawi(nx, ny, nz));
			
				}
			}
		}
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[k][j][i];
				if (board[k][j][i] == 1) q.push(tomawi( k,j,i ));
			}
		}
	}
	BFS();
	Val();
	
	if (result == false) cout << -1;
	else cout << max_val - 1;
}