#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int dp_max[3];
	int dp_min[3];

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		if (i == 0)
		{
			dp_max[0] = a;
			dp_max[1] = b;
			dp_max[2] = c;

			dp_min[0] = a;
			dp_min[1] = b;
			dp_min[2] = c;
		}
		else
		{
			int last_max_0 = dp_max[0];
			int last_max_1 = dp_max[1];
			int last_max_2 = dp_max[2];
			dp_max[0] = a + max(last_max_0,last_max_1);
			dp_max[1] = b + max(last_max_0, max(last_max_1,last_max_2));
			dp_max[2] = c + max(last_max_1,last_max_2);

			int last_0 = dp_min[0];
			int last_1 = dp_min[1];
			int last_2 = dp_min[2];
			dp_min[0] = a + min(last_0, last_1);
			dp_min[1] = b + min(last_0, min(last_1, last_2));
			dp_min[2] = c + min(last_1, last_2);
		}
	}
	cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << " " << min(dp_min[0], min(dp_min[1], dp_min[2]));
}