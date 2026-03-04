#include <iostream>
#include <vector>

using namespace std;

int Oneresult = 0;
int Zeroresult = 0;

bool check(const vector<vector<int>> &vec,int row, int col, int size) {

	bool chch = vec[row][col] == 0 ? false : true;

	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (vec[i][j] == 0 && chch == false || vec[i][j] == 1 && chch == true)
				continue;
			else
				return false;		
		}
	}
	if (chch == true)
	{
		Oneresult++;
		return 1;
	}
	else
	{
		Zeroresult++;
		return 1;
	}
}

void solve(const vector<vector<int>> &vec, int row, int col, int size) {
	if (!check(vec, row, col, size))
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