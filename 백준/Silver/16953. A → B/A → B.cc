#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long a, b;

long long BFS() {
	queue<pair<long long, long long>> q;
	q.push({a,1});

	while (!q.empty())
	{
		long long cx = q.front().first;
		long long cnt = q.front().second;
		q.pop();

		if (cx == b)
			return cnt;

		long long nx1 = cx * 2;
		long long nx2 = cx * 10 + 1;

		if (nx1 <= b)
		{
			q.push({nx1, cnt+1});
		}
		if (nx2 <= b)
		{
			q.push({nx2, cnt+1});
		}
	}
	return -1;
		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	cout << BFS() << "\n";
}