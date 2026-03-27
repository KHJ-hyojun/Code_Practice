#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		multiset<long int> ms;

		for (int i = 0; i < k; i++)
		{
			char ID;
			long int num;
			cin >> ID >> num;

			if (ID == 'I')
			{
				ms.insert(num);
			}
			else
			{
				if (num == -1 && !ms.empty())
				{
					ms.erase(ms.begin());
				}
				else if (num == 1 && !ms.empty())
				{
					ms.erase(--ms.end());
				}
			}
		}
		if (ms.empty())
			cout << "EMPTY" << "\n";
		else
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
	}
}