#include <iostream>
#include <vector>

using namespace std;


int n, m;
int arr[10];

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
	else
	{
		for (int i = start; i <= n; i++)
		{

			arr[depth] = i;
			DFS(i , depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	DFS(1, 0);
}