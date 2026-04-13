#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	int result[501][501] = { 0 };
	int board[501][501];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> board[i][j];
		}
	}

	result[0][0] = board[0][0];


	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				result[i][j] = result[i - 1][j] + board[i][j];
			}
			else if (j == i )
			{
				result[i][j] = result[i - 1][j-1] + board[i][j];
			}
			else
			{
				result[i][j] = max(result[i - 1][j - 1], result[i - 1][j]) + board[i][j];
			}
		}
	}

	int final_result = 0;
	for (int i = 0; i < n; i++)
	{
		if (final_result < result[n-1][i])
			final_result = result[n-1][i];
	}

	cout << final_result;

}