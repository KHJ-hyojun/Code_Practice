#include <iostream>
#include <vector>

using namespace std;

int parent[100001];
bool visited[100001];
vector<int> tree[100001];

int n;

void DFS(int current) {
	
	visited[current] = true;

	for (int i = 0; i < tree[current].size(); i++)
	{
		int next_node = tree[current][i];

		if (!visited[next_node])
		{
			parent[next_node] = current;
			DFS(next_node);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;

		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	DFS(1);
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}

}