#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int D(int x) {
	if (x * 2 < 10000)
		return x * 2;
	else
		return (x * 2) % 10000;
}

int S(int x) {
	if (x == 0)
		return 9999;
	else
		return x - 1;
}

int L(int x) {
	int nam = x % 1000;
	int mok = x / 1000;

	return nam * 10 + mok;
}

int R(int x) {
	int nam = x % 10;
	int mok = x / 10;

	return nam * 1000 + mok;
}


vector<int> visited;
int board[10001] = { 0 };
int parent[10001] = { 0 };
char command[10001];

void BFS(int st, int tg) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty())
	{
		int cx = q.front();
		q.pop();
		if (cx == tg) return;

		// D
		int Dx = D(cx);
		if (visited[Dx] == 0)
		{
			visited[Dx] = 1;
			parent[Dx] = cx;
			command[Dx] = 'D';
			q.push(Dx);
		}

		// L
		int Lx = L(cx);
		if (visited[Lx] == 0)
		{
			visited[Lx] = 1;
			parent[Lx] = cx;
			command[Lx] = 'L';
			q.push(Lx);
		}
		
		// S
		int Sx = S(cx);
		if (visited[Sx] == 0)
		{
			visited[Sx] = 1;
			parent[Sx] = cx;
			command[Sx] = 'S';
			q.push(Sx);
		}

		// R
		int Rx = R(cx);
		if (visited[Rx] == 0)
		{
			visited[Rx] = 1;
			parent[Rx] = cx;
			command[Rx] = 'R';
			q.push(Rx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	while (t--)
	{
		int start, target;
		cin >> start >> target;

		visited.assign(10001, 0);
		BFS(start, target);

		string ans = "";
		int curr = target;
		
		while (curr != start)
		{
			ans += command[curr];
			curr = parent[curr];
		}

		reverse(ans.begin(), ans.end());

		cout << ans << "\n";
	}
}