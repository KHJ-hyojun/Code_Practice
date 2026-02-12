#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	

	while (T--) {
		int n;
		cin >> n;
		unordered_map<string, int> mp;

		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;

			mp[b]++;

		}
		int result = 1;

		for (auto& p : mp)
		{
			if (p.second != 0)
				result *= (p.second + 1);

		}
		cout << result - 1 <<"\n";


	}
}