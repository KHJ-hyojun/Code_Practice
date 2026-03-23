#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int resultcnt = 0;

void Cal(int col , int row,int size) {
	if (size == 0) return;
	if (col < size)
	{
		if (row < size)
		{
			// 첫번째
			if (size == 1) return;
			Cal(col, row, size / 2);
		}
		else
		{
			// 두번째
			resultcnt += size * size;
			if (size == 1) return;
			Cal(col, row - size, size / 2);
		}
	}
	else
	{
		if (row < size)
		{
			// 세번째
			resultcnt += size * size * 2;
			if (size == 1) return;
			Cal(col - size, row, size / 2);
		}
		else
		{
			// 네번째
			resultcnt += size * size * 3;
			if (size == 1) return;
			Cal(col - size, row - size, size / 2);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,r, c;
	cin >> N >> r >> c;

	int len = 1 << N;
	
	Cal(r, c, len / 2);

	cout << resultcnt;
	
}