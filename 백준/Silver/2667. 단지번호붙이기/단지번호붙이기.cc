#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Xarr[4] = { 1,-1,0,0 };
int Yarr[4] = { 0,0,1,-1 };

vector<string> board;
vector<vector<bool>> visited;

int n;
int house_count;


void DFS(int col, int row) {
	visited[col][row] = true;
	house_count++;

	for (int i = 0; i < 4; i++)
	{
		int nx = col + Xarr[i];
		int ny = row + Yarr[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			if(board[nx][ny] == '1' && visited[nx][ny] == 0)
			{
				DFS(nx, ny);
			}
	}
	
}

int main() { 

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	board.resize(n);
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '1' && visited[i][j] == 0)
			{
				house_count = 0;
				DFS(i, j);
				result.push_back(house_count);
			}
		}
	}
	cout << result.size() << "\n";

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}