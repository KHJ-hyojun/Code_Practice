#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for (int _ = 0; _ < n; _++)
	{
		long long input;
		cin >> input;

		if (input == 0)
		{
			if (pq.size())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << 0 << "\n";
		}
		else
		{
			pq.push(input);
		}		
	}
}