#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> q;

	for (int _ = 0; _ < n; _++)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			if (q.empty())
				cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(input);
	}
}