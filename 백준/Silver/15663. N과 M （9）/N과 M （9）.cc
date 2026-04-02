#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10001];
int result[10001];
int visited[10001];


void DFS(int depth) {
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int last_val = 0;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && arr[i] != last_val)
		{
			visited[i] = true;

			result[depth] = arr[i];
			last_val = arr[i];

			DFS(depth + 1);

			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	DFS(0);
	
}