#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



int main()
{
	int k, n;
	cin >> k >> n;
	vector<long long> vec(k);

	long long max_len = 0;

	// 가지고 있는 것 초기화 & 정렬
	for (int _ = 0; _ < k; _++)
	{
		int a;
		cin >> a;

		vec[_] = a;

		if (vec[_] > max_len)
			max_len = vec[_];
	}

	long long left = 1;
	long long right = max_len;

	long long result = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long sum = 0;
		
		for (int _ = 0; _ < k; _++)
		{
			sum += vec[_] / mid;
		}

		if (sum >= n)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result;
	
}