#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heiresult = 0;
int timeresult = 1e9;

void Cal(const vector<vector<int>>& vec, int height, long long initial_b) {

	long long time = 0;
	long long inventory = initial_b;


	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			int diff = vec[i][j] - height;
			if (diff > 0)
			{
				time += diff * 2;
				inventory += diff;
			}
			else if (diff < 0)
			{
				time += (-diff);
				inventory -= (-diff);
			}
		}
	}
	
	if (inventory >= 0)
	{
		if (time <= timeresult)
		{
			timeresult = (int)time;
			heiresult = height;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long b;
	cin >> n >> m >> b;

	vector<vector<int>> board(n, vector<int>(m));

	int least = 0;
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> board[i][j];
			num = board[i][j];

			if (num < least)
				least = num;
			if (num > max)
				max = num;
			
		}
	}


	for (int i = least; i <= max; i++)
	{
		Cal(board, i, b);
	}

	cout << timeresult << " " << heiresult;

}