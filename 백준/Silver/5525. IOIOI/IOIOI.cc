#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string s;
	cin >> n >> m >> s;

	int count = 0;
	int result = 0;

	for (int i = 0; i < m-2;)
	{
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			count++;
			if (count == n)
			{
				result++;
				count--;
			}
			i += 2;
		}
		else
		{
			count = 0;
			i++;
		}
	}

	cout << result;
}