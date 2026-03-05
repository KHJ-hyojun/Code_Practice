#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;

	vector<long long> vec(n);

	long long left = 0;
	long long right = 0;
	

	for (long long i = 0; i < n; i++)
	{
		long long len;
		cin >> len;

		vec[i] = len;

		if (len > right)
		{
			right = len;
		}
	}

	long long ans = 0;
	

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long result = 0;
		
		for (long long num : vec)
		{
			if (num > mid)
				result += num - mid;
		}

		if (result >= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else if (result < m)
			right = mid - 1;
	}
	cout << ans;
}