#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> graph[1001];
int dist[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int start, finish, cost;
		cin >> start >> finish >> cost;

		graph[start].push_back({ finish, cost });
	}
	int start_city, end_city;
	cin >> start_city >> end_city;

	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}

	priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start_city] = 0;
	pq.push({ 0,start_city });

	while (!pq.empty())
	{
		int curr_cost = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();


		if (curr_cost > dist[curr_node]) continue;
		{
			if (curr_node == end_city) break;

			for (int i = 0; i < graph[curr_node].size(); i++)
			{
				int next_node = graph[curr_node][i].first;
				int bus_cost = graph[curr_node][i].second;

				int next_cost = curr_cost + bus_cost;

				if (next_cost < dist[next_node])
				{
					dist[next_node] = next_cost;
					pq.push({ next_cost, next_node });
				}
			}
		}
	}
	cout << dist[end_city] << "\n";
}