#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int result[10];
int arr[10];
bool visited[10] = { false };

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
	
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			result[depth] = arr[i];

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