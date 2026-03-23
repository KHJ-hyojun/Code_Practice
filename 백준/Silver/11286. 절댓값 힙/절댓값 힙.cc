#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				result.push_back(0);
			}
			else
			{
				result.push_back(pq.top());
				pq.pop();
			}

		}
		else
			pq.push(x);
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}