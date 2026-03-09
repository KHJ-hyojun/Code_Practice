#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}


	vector<int> sorted = vec;
	sort(sorted.begin(), sorted.end());

	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(sorted.begin(), sorted.end(), vec[i]);

		cout << it - sorted.begin() << " ";
		

	}
	
}