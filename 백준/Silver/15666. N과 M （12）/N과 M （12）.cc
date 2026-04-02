#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[10001];
int result[10001];

void DFS(int start, int depth) {
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}


	for (int i = start; i < n; i++)
	{
		result[depth] = arr[i];
		DFS(i, depth + 1);
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
	n = unique(arr, arr + n) - arr;



	DFS(0, 0);
}