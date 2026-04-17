#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int dist[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	deque<int> dq;
	dq.push_back(n);
	dist[n] = 0;

	while (!dq.empty())
	{
		int curr = dq.front();
		dq.pop_front();

		if (curr == k)
		{
			cout << dist[curr] << "\n";
			break;
		}

		int next_tel = curr * 2;
		if (next_tel >= 0 && next_tel <= 100000 && (dist[next_tel] == -1 || dist[next_tel] > dist[curr]))
		{
			dist[next_tel] = dist[curr] ;
			dq.push_front(next_tel);
		}

		int next1 = curr + 1;
		if (next1 >= 0 && next1 <= 100000 && (dist[next1] == -1 || dist[next1] > dist[curr]))
		{
			dist[next1] = dist[curr] + 1;
			dq.push_back(next1);
		}

		int next_1 = curr - 1;
		if (next_1 >= 0 && next_1 <= 100000 && (dist[next_1] == -1 || dist[next_1] > dist[curr]))
		{
			dist[next_1] = dist[curr] + 1;
			dq.push_back(next_1);
		}
	}
}