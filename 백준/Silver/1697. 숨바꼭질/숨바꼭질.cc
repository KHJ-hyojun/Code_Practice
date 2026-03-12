#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist(100005, -1);

int n, k;



int BFS(int start, int finish) {

	queue<int> q;

	q.push(start);
	dist[start] = 0;

	

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == finish)
			return dist[curr];

		int arr[3] = { curr +1, curr -1 , curr *2 };
		for (int nx : arr)
		{
			if (nx >= 0 && nx <= 100000 && dist[nx] == -1)
			{
				q.push(nx);
				dist[nx] = dist[curr] + 1;
			}
		}

		

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << BFS(n,k);
}