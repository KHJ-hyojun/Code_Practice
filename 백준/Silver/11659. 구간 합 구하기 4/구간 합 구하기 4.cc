#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long> v(n + 1);
	v[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		long num;
		cin >> num;
		v[i] = v[i - 1] + num;
	}

	while (m--)
	{
		int a, b;
		int result = 0;
		cin >> a >> b;

		cout << v[b] - v[a - 1] << "\n";
	}
}