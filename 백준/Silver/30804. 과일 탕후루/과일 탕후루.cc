#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int fruit_count[10] = { 0 };
	int type_cnt = 0;
	int left = 0;
	int max_len = 0;

	for (int right = 0; right < n; right++)
	{
		if (fruit_count[arr[right]] == 0)
			type_cnt++;
		fruit_count[arr[right]]++;

		while (type_cnt > 2)
		{
			fruit_count[arr[left]]--;
			if (fruit_count[arr[left]] == 0)
				type_cnt--;
			left++;
		}
		max_len = max(max_len, right - left+ 1);

	}

	cout << max_len;
}