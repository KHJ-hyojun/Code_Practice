#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

deque<int> parseInput(string input) {
	deque<int> dq;

	string inner = input.substr(1, input.length() - 2);

	stringstream ss(inner);
	string token;

	while (getline(ss, token, ','))
	{
		if (!token.empty())
			dq.push_back(stoi(token));
	}
	return dq;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string s, input;
		int n;
		cin >> s >> n >> input;

		deque<int> board = parseInput(input);

		bool isReverse = false;
		bool error = false;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
				isReverse = !isReverse;
			else
			{
				if (!board.empty())
				{
					if (isReverse == true)
					{
						board.pop_back();
					}
					else
					{
						board.pop_front();
					}
				}
				else
				{
					error = true;
					break;
				}
			}
		}
		if (error == true)
			cout << "error" << "\n";
		else if (board.empty())
		{
			cout << "[]\n";
		}
		else
		{
			if (isReverse)
			{
				cout << '[' << board[board.size() - 1];
				for (int i = board.size() - 2 ; i >= 0; i--)
				{
					cout << ',' << board[i];
				}
				cout << ']' << "\n";
			}
			else
			{
				cout << '[' << board[0];
				for (int i = 1; i < board.size(); i++)
				{
					cout << ',' << board[i];
				}
				cout << ']' <<"\n";
			}
		}
	}
}