#include <iostream>

using namespace std;

int arr[10];
int n, m;

void DFS(int start, int depth) {
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++)
	{
		arr[depth] = i;
		DFS(i + 1, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	DFS(1, 0);

}