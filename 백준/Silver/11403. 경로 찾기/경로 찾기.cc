#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> possible;

void DFS(int start, int current) {

	for (int _ = 0; _ < board[current].size(); _++)
	{
		int gogo = board[current][_];

		if (possible[start][gogo] == 0)
		{
			possible[start][gogo] = 1;
			DFS(start, gogo);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	board.assign(n+1, vector<int>());
	possible.assign(n+1, vector<int>(n+1, 0));
	


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{

			int x;
			cin >> x;

			if (x == 1)
				board[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		DFS(i,i);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << possible[i][j] << " ";
		}
		cout << "\n";
	}

}
