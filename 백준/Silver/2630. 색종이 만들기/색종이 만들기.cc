#include <iostream>
#include <vector>

using namespace std;

int Oneresult = 0;
int Zeroresult = 0;

bool check(const vector<vector<int>> &vec,int row, int col, int size) {

	int color = vec[row][col];

	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (vec[i][j] != color)
				return false;
		}
	}
	return true;
}


void solve(const vector<vector<int>>& vec, int row, int col, int size) {
	if (check(vec, row, col, size))
	{
		if (vec[row][col] == 1)
			Oneresult++;
		else
			Zeroresult++;
		return;
	}
	else
	{
		int new_size = size / 2;
		solve(vec, row, col, new_size);
		solve(vec, row, col + new_size, new_size);
		solve(vec, row + new_size, col, new_size);
		solve(vec, row + new_size, col + new_size, new_size);
	}
}

int main() {
	int size;
	cin >> size;

	vector<vector<int>> board(size,vector<int>(size));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> board[i][j];
		}
	}
	
	solve(board, 0, 0, size);
	cout << Zeroresult << "\n" << Oneresult;

}	