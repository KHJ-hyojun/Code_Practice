#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting {
	int start;
	int end;
};

using namespace std;

bool compare(Meeting a, Meeting b) {
	if (a.end == b.end) return a.start < b.start;
	else return a.end < b.end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Meeting> board(N);

	for (int i = 0; i < N; i++)
	{
		cin >> board[i].start;
		cin >> board[i].end;
	}

	sort(board.begin(), board.end(), compare);

	int result = 1;
	int end_time = board[0].end;

	for (int i = 1 ; i < N ; i++)
	{
		if (board[i].start >= end_time)
		{
			result++;
			end_time = board[i].end;
		}
	}
	cout << result;
}